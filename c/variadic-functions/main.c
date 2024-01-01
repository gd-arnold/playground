#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#include "dbg.h"

uint32_t sum_ints(uint32_t num, ...)
{
    va_list args;
    va_start(args, num);

    uint32_t sum = 0;

    for (uint32_t i = 0; i < num; i++)
        sum += va_arg(args, uint32_t);

    return sum;
}

int main(int argc, char* argv[])
{
    uint32_t sum = sum_ints(3, 19, 43, 2);
    debug("%d", sum);

    return 0;
}
