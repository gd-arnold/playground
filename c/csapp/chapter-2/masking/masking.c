#include <stdio.h>

int main()
{
    int x = 0x87654321;
    int a = x & 0xFF;
    int b = x ^ ~0xFF;
    int c = x | 0xFF;

    printf("0x%.8x\n", a);
    printf("0x%.8x\n", b);
    printf("0x%.8x\n", c);
    return 0;
}
