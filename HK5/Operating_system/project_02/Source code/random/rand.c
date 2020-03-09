#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/uaccess.h>

static dev_t first;
static struct cdev c_dev;
static struct class* cl;

static int dev_open(struct inode* i, struct file* f)
{
    printk(KERN_INFO "Rand open!\n");
    return 0;
}

static int dev_close(struct inode* i, struct file* f)
{
    printk(KERN_INFO "Rand close!\n");
    return 0;
}

static ssize_t dev_read(struct file* f, char __user* buf, size_t len, loff_t* off)
{
    int numb = 0;

    printk(KERN_INFO "Rand read!\n");

    // Lấy số ngẫu nhiên.
    get_random_bytes(&numb, sizeof(int));

    printk("Random number: %d\n", numb);

    // Copy chuỗi vào user buffer.
    if (copy_to_user(buf, &numb, sizeof(numb)))
        return -EFAULT;

    return 0;
}

static struct file_operations pugs_fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .release = dev_close,
    .read = dev_read,
};

static int __init mod_init(void)
{
    printk(KERN_INFO "Rand initializing!");

    // Đăng ký số hiệu.
    if (alloc_chrdev_region(&first, 0, 1, "Rand") < 0)
    {
        printk(KERN_ALERT "Cannot register!");
        return -1;
    }

    // Tạo class.
    if (!(cl = class_create(THIS_MODULE, "CRand")))
    {
        printk(KERN_ALERT "Cannot create class!");
        unregister_chrdev_region(first, 1);
        return -1;
    }

    // Tạo thiết bị.
    if (!device_create(cl, NULL, first, NULL, "rand"))
    {
        printk(KERN_ALERT "Cannot create device!");
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return -1;
    }

    // Thiết lập và thêm thiết bị vào hệ thống.
    cdev_init(&c_dev, &pugs_fops);
    if (cdev_add(&c_dev, first, 1) < 0)
    {
        printk(KERN_ALERT "Cannot add device!");
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return -1;
    }

    return 0;
}

static void __exit mod_exit(void)
{
    // Xóa thiết bị ra khỏi hệ thống.
    cdev_del(&c_dev);
    // Hủy thiết bị.
    device_destroy(cl, first);
    // Hủy class.
    class_destroy(cl);
    // Xóa số hiệu đã đăng ký.
    unregister_chrdev_region(first, 1);

    printk(KERN_INFO "Rand removed!");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("1712358-1712369-1712379");
MODULE_DESCRIPTION("Random number module.");
MODULE_VERSION("1.0");