#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    int a = invert(0b1000111001, 4, 3);

    printf("%d\n", a);
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned a = (~x >> (p - n + 1) & ~(~0 << n)) << (p - n + 1);
    unsigned b = x & ((~0 << (p + 1)) | ~(~0 << (p - n + 1)));

    return a | b;
}
