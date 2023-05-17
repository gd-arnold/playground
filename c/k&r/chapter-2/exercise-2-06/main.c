#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    int a = setbits(0b1000111001, 4, 3, 0b1101111101);

    printf("%d\n", a);
    return 0;
}


// p = 4, n = 3, y = 1101111101, x = 1000111001
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // ~(~0 << 3) -> 0000000111
    // y & 0000000111 -> 0000000101
    // y << 2 -> 0000010100
    unsigned a = (y & ~(~0 << n)) << (p - n + 1);

    // 1111100000 | 0000000011 (~0 << 5 | ~(~0 << 2)) -> 1111100011
    // 1000100001 -> x & 1111100011
    unsigned b = x & ((~0 << (p + 1)) | ~(~0 << (p - n + 1)));

    // 0000010100 a
    // 1000100001 b
    // a | b -> 1000110101
    return a | b;
}
