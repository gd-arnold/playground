#include <stdio.h>

#define LEN 5

int binsearch(int x, int v[], int n);

int main() {
    int nums[LEN] = {3, 9, 13, 15, 19};
    int x = 15;

    int indx = binsearch(x, nums, LEN);

    printf("%d\n", indx);
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (x < v[mid]) high = mid - 1;
        else low = mid + 1;
    }

    if (x == v[low - 1]) return low - 1;

    return -1;
}
