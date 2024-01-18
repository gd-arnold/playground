#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dbg.h"

#define PI 3.14159265358979323846

static const double eps = 1.0E-6;

double derivative(double f(double x), double x) {
    return (f(x + eps) - f(x -  eps)) / (2 * eps);
}

bool is_almost_equal(double a, double b) {
    return fabs(a - b) < eps;
}

int main(int argc, char *argv[]) {
    const double points[] = { 0, PI / 2, PI / 4 };

    for (size_t i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
        double result = derivative(sin, points[i]);
        double expected = cos(points[i]);

        check(is_almost_equal(result, expected), 
            "Calculating sin'(%f) failed.\nExpected: %f\nResult: %f", points[i], expected, result);

        log_info("sin'(%f) is %f", points[i], result);
    }

    return EXIT_SUCCESS;

error:
    return EXIT_FAILURE;
}
