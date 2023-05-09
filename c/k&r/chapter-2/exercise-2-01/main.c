#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("CHAR RANGE\n");
    printf("unsigned char: [0, %d]\n", UCHAR_MAX);
    printf("signed char [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);

    printf("INT RANGE\n");
    printf("unsigned int: [0, %u]\n", UINT_MAX);
    printf("signed int: [%d, %d]\n", INT_MIN, INT_MAX);

    printf("SHORT INT RANGE\n");
    printf("unsigned short int: [0, %u]\n", USHRT_MAX);
    printf("signed short int: [%d, %d]\n", SHRT_MIN, SHRT_MAX);

    printf("LONG INT RANGE\n");
    printf("unsigned long int: [0, %lu]\n", ULONG_MAX);
    printf("signed long int: [%ld, %ld]\n", LONG_MIN, LONG_MAX);

    return 0;
}
