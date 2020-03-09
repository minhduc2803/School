#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int numb = 0;
    char buf[11] = {};

    int fd = open("/dev/rand", O_RDONLY);
    if (fd < 0)
        return -1;

    if (read(fd, buf, 11))
        return -2;

    memcpy(&numb, buf, sizeof(int));
    printf("Random number: %d\n", numb);

    return 0;
}