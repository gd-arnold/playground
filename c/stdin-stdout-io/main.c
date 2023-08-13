#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 1024

int main(int argc, char** argv)
{
    char buffer[BUFFSIZE];
    int n;

    while ((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buffer, n) != n)
            exit(1);

    if (n < 0)
        exit(1);

    exit(0);
}
