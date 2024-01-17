#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int32_t a[], uint32_t n);

void bubble_sort(int32_t a[], uint32_t n);

void insertion_sort(int32_t a[], uint32_t n);

int32_t* merge_sort(int32_t arr[], uint32_t n);
int32_t* merge(int32_t a[], uint32_t na, int32_t b[], uint32_t nb);

void swap(int32_t* a, int32_t* b);
void print_arr(int32_t a[], uint32_t n);

int main(int argc, char* argv[])
{
    int32_t a[] = {3, -3, 1, 9, 14, 2, 8, 17, 2, 4, 3, -2, 8, -1};
    uint32_t n = sizeof(a) / sizeof(a[0]);

    int32_t* sorted = merge_sort(a, n);
    print_arr(sorted, n);
    free(sorted);
    
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

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void insertion_sort(int32_t a[], uint32_t n)
{
    for (uint32_t i = 1; i < n; i++) {
        for (uint32_t j = i; j > 0 && a[j - 1] > a[j]; j--)
            swap(&a[j], &a[j - 1]);
    }
}

// Time Complexity: O(n*logn)
// Space Complexity: O(n)
int32_t* merge_sort(int32_t arr[], uint32_t n)
{
    if (n == 1) {
        int32_t* a = (int32_t*) malloc(sizeof(int32_t) * n);
        a[0] = arr[0];

        return a;
    }

    // Split array in half
    uint32_t na = n / 2;
    uint32_t nb = n - na;

    int32_t* a = (int32_t*) malloc(sizeof(int32_t) * na);
    int32_t* b = (int32_t*) malloc(sizeof(int32_t) * nb);

    for (uint32_t i = 0; i < na; i++) a[i] = arr[i];
    for (uint32_t i = 0; i < nb; i++) b[i] = arr[na + i];

    // Sort split arrays
    int32_t* sorted_a = merge_sort(a, na);
    int32_t* sorted_b = merge_sort(b, nb);

    free(a);
    free(b);

    // Merge sorted arrays
    int32_t* merged = merge(sorted_a, na, sorted_b, nb);

    free(sorted_a);
    free(sorted_b);

    return merged;
}

// Time Complexity: O(na + nb)
// Space Complexity: O(na + nb)
int32_t* merge(int32_t a[], uint32_t na, int32_t b[], uint32_t nb)
{
    int32_t* merged = (int32_t*) malloc(sizeof(int32_t) * (na + nb));
    uint32_t a_i, b_i, merged_i;
    a_i = b_i = merged_i = 0;

    while (a_i < na && b_i < nb)
    {
        if (a[a_i] < b[b_i])
            merged[merged_i++] = a[a_i++];
        else
            merged[merged_i++] = b[b_i++];
    }

    while (a_i < na)
        merged[merged_i++] = a[a_i++];

    while (b_i < nb)
        merged[merged_i++] = b[b_i++];

    return merged;
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
