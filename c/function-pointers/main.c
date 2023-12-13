#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int (*compare_cb)(int32_t a, int32_t b);

void die(const char message[])
{
    if (errno)
        perror(message);
    else
        printf("ERROR: %s\n", message);

    exit(1);
}

int sorted_order(int32_t a, int32_t b) {
    return a > b;
}

int reverse_order(int32_t a, int32_t b) {
    return a < b;
}

int random_order(int32_t a, int32_t b) {
    return rand() % 2;
}

void bubble_sort(int32_t nums[], int32_t count, compare_cb cmp)
{
    for (int32_t c = count - 1; c > 0; c--) {
        for (int32_t i = 0; i < c; i++) {
            if (cmp(nums[i], nums[i + 1])) {
                int32_t temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2) die("USAGE: main 4 3 1 8 4");

    uint32_t count = argc - 1;
    char** nums_input = argv + 1;

    int32_t nums[count];

    for (uint32_t i = 0; i < count; i++)
        nums[i] = atoi(nums_input[i]);

    bubble_sort(nums, count, reverse_order);

    for (uint32_t i = 0; i < count; i++)
        printf("%d ", nums[i]);

    printf("\n");
    
    return 0;
}
