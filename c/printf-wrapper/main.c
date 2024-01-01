#include <stdio.h>
#include <stdarg.h>

void printf_wrapper(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    vprintf(format, args);
}

int main(int argc, char* argv[])
{
    printf_wrapper("2 + 2 = %d\n", 2 + 2);
    return 0;
}
