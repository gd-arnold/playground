#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

// Define options
#define FOO 0x01 // 00000001
#define BOO 0X02 // 00000010
#define MOO 0x04 // 00000100

void func(uint8_t options)
{
    if (options & FOO)
    {
        printf("foo is selected... \n");
    }
    if (options & BOO)
    {
        printf("boo is selected... \n");
    }
    if (options & MOO)
    {
        printf("moo is selected... \n");
    }
}

int main(int argc, char **argv)
{
    func(FOO | BOO);

    exit(0);
}