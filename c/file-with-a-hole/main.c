#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;

    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int bufLen = 10;
    int hole = 100;

    if ((fd = creat("file-with-a-hole", mode)) < 0)
        exit(1);
    
    if (write(fd, buf1, bufLen) != bufLen)
        exit(1);
    // offset now = 10

    if (lseek(fd, hole, SEEK_CUR) == -1)
        exit(1);
    // offset now = 10 + hole = 110

    if (write(fd, buf2, bufLen) != bufLen)
        exit(1);
    // offset now = 110 + 10 = 120

    exit(0);
}
