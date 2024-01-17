#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int32_t a[], uint32_t n);
void bubble_sort(int32_t a[], uint32_t n);

void swap(int32_t* a, int32_t* b);
void print_arr(int32_t a[], uint32_t n);

int main(int argc, char* argv[])
{
    int32_t a[] = {3, -3, 1, 9, 2, 8, 17, 2, 4, 3, -2, 8};
    uint32_t n = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, n);
    print_arr(a, n);

    return EXIT_SUCCESS;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selection_sort(int32_t a[], uint32_t n)
{
    for (uint32_t i = 0; i < n - 1; i++) {
        uint32_t iMin = i;

        for (uint32_t j = i + 1; j < n; j++) {
            if (a[j] < a[iMin])
                iMin = j;
        }

        swap(&a[i], &a[iMin]);
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void bubble_sort(int32_t a[], uint32_t n)
{
    for (uint32_t i = 1; i < n; i++) {
        bool is_already_sorted = true;
        for (uint32_t j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                is_already_sorted = false;
            }
        }

        if (is_already_sorted) break;
    }
}

void print_arr(int32_t a[], uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void swap(int32_t* a, int32_t* b)
{
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}
