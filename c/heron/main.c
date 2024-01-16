#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[])
{
    for (uint32_t i = 1; i < argc; i++) {
        double a = strtod(argv[i], 0);
        double x = 1.0;
        double prod = a * x;

        while (prod < eps1m01 || prod > eps1p01) {
            if (prod < eps1m01) x *= 2.0;
            else if (prod > eps1p01) x *= 0.5;
            prod = a * x;
        }

        while (prod < eps1m24 || prod > eps1p24) {
            x *= (2.0 - prod);
            prod = a * x;
        }

        printf("%f %f %f\n", a, x, prod);
    }

    return EXIT_SUCCESS;
}
