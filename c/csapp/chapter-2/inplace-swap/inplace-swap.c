#include <stdio.h>

// a ^ a = 0
void inplace_swap(int* px, int* py) {
    *py = *px ^ *py;
    *px = *px ^ *py;
    *py = *px ^ *py;
}

int main()
{
    int x = 5, y = 2;
    inplace_swap(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
}
