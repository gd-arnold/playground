#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y);

int main()
{
    printf("%d\n", uadd_ok(4, 5));
    printf("%d\n", uadd_ok(UINT_MAX, 5));
    return 0;
}

int uadd_ok(unsigned x, unsigned y) {
    return x + y >= x;
}
