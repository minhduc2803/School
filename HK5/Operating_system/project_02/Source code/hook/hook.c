#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kallsyms.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>

char filename[256] = {};
int fid = 0;
void** sys_call_table = NULL;

asmlinkage int (*old_open)(const char*, int, mode_t) = NULL;
asmlinkage ssize_t (*old_write)(int, const void*, size_t) = NULL;

// Lấy tên file từ đường dẫn.
void get_filename(const char* pathname)
{
    int i, j, l;

    l = j = strlen(pathname) - 1;
    while (j >= 0)
    {
        if (pathname[j] == '/')
            break;

        --j;
    }
    ++j;
    i = j;

    while (i <= l)
    {
        filename[i - j] = pathname[i];
        ++i;
    }
    filename[i] = '\0';
}

// Hàm hook syscall open.
asmlinkage int hook_open(const char* pathname, int flags, mode_t mode)
{
    // Lưu tên file được mở bởi tiến trình.
    get_filename(pathname);
    // Lưu id của tiến trình mở file.
    fid = current->pid;

    printk(KERN_INFO "Hooked syscall open:\n");
    printk(KERN_INFO "\tProcess name: %s\n", current->comm);
    printk(KERN_INFO "\tFilename: %s\n", filename);

    // Trả về syscall cũ.
    return old_open(pathname, flags, mode);
}

// Hàm hook syscall write.
asmlinkage ssize_t hook_write(int fd, const void* buf, size_t count)
{

    ssize_t l;
    // Lấy số byte được ghi.
    l = old_write(fd, buf, count);

    // Chỉ ghi nếu có file được mở trước đó.
    if (current->pid == fid)
    {
        printk(KERN_INFO "Hooked syscall write:\n");
        printk(KERN_INFO "\tProcess name: %s\n", current->comm);
        printk(KERN_INFO "\tFilename: %s\n", filename);

        if (l != -1)
            printk(KERN_INFO "\tNumber of bytes written: %zd\n", l);
        else
            printk(KERN_INFO "\tNumber of bytes written: 0\n");
    }

    // Trả về kết quả syscall cũ.
    return l;
}

// Tắt bảo vệ ghi trên cpu.
void disable_page_protection(void)
{
    unsigned long cr0 = read_cr0();

    cr0 &= ~(1 << 16);
    write_cr0(cr0);
}

// Bật lại bảo vệ ghi trên cpu.
void enable_page_protection(void)
{
    unsigned long cr0 = read_cr0();

    cr0 |= (1 << 16);
    write_cr0(cr0);
}

int __init hook_init(void)
{
    printk(KERN_INFO "Hook initializing!\n");

    // Tìm bảng 'sys_call_table'.
    if (!(sys_call_table = (void*)kallsyms_lookup_name("sys_call_table")))
    {
        printk(KERN_ALERT "Hook failed to find 'sys_call_table'!\n");
        return -1;
    }

    // Lưu syscall gốc.
    old_open = sys_call_table[__NR_open];
    old_write = sys_call_table[__NR_write];

    disable_page_protection();
    // Thay thế syscall gốc.
    sys_call_table[__NR_open] = hook_open;
    sys_call_table[__NR_write] = hook_write;
    enable_page_protection();

    return 0;
}

void __exit hook_exit(void)
{
    if (sys_call_table)
    {
        disable_page_protection();
        // Khôi phục lại syscall như ban đầu.
        sys_call_table[__NR_open] = old_open;
        sys_call_table[__NR_write] = old_write;
        enable_page_protection();
    }

    printk(KERN_INFO "Hook removed!\n");
}

module_init(hook_init);
module_exit(hook_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("1712358-1712369-1712379");
MODULE_DESCRIPTION("Hook syscall open and write module.");
MODULE_VERSION("1.0");
