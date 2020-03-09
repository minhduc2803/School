#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("file.txt", "w+");
    if (!fp)
        return -1;

    char str[] = "Writing something...";

    fprintf(fp, "%s", str);

    fclose(fp);

    return 0;
}
