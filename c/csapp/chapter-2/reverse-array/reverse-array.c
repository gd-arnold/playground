#include <stdio.h>

#define LEN 5

void inplace_swap(int* px, int* py);
void reverse_array(int a[], int cnt);

int main()
{
    int a[LEN] = { 1, 2, 3, 4, 5 };
    int i;

    reverse_array(a, LEN);

    for (i = 0; i < LEN; i++)
        printf("%d ", a[i]);
}

void inplace_swap(int* px, int* py) {
    *py = *px ^ *py;
    *px = *px ^ *py;
    *py = *px ^ *py;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}
