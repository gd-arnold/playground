#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    struct stat buf;
    char *type;

    for (int i = 1; i < argc; i++)
    {
        if (lstat(argv[i], &buf) < 0) {
            printf("lstat error. argument: %s", argv[i]);
            continue;
        }

        if (S_ISREG(buf.st_mode))
            type = "regular";
        else if (S_ISDIR(buf.st_mode))
            type = "directory";
        else if (S_ISCHR(buf.st_mode))
            type = "character special";
        else if (S_ISBLK(buf.st_mode))
            type = "block special";
        else if (S_ISFIFO(buf.st_mode))
            type = "fifo";
        else if (S_ISLNK(buf.st_mode))
            type = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            type = "socket";
        else
            type = "unknown";

        printf("%s type: %s \n", argv[i], type);
    }

    exit(0);
}
