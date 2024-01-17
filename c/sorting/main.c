#include <stdint.h>
#include <stdio.h>

void selection_sort(int32_t a[], uint32_t n);

void swap(int32_t* a, int32_t* b);
void print_arr(int32_t a[], uint32_t n);

int main(int argc, char* argv[])
{
    int32_t a[] = {3, -3, 1, 9, 2, 8, 17, 2, 4, 3, -2, 8};
    uint32_t n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);
    print_arr(a, n);

    return EXIT_SUCCESS;
}

// Time Complexity: O(n^2)
// Memory Complexity: O(1)
void selection_sort(int32_t a[], uint32_t n)
{
    for (uint32_t i = 0; i < n - 1; i++) {
        uint32_t idx = i;

        for (uint32_t j = i + 1; j < n; j++) {
            if (a[j] < a[idx])
                idx = j;
        }

        swap(&a[i], &a[idx]);
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
