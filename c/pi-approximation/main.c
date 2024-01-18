#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// leibniz approximation
double approx_pi(uint64_t max_terms) {
    double pi_approximation = 0.0;

    for (uint64_t i = 0; i < max_terms; i++) {
        double term = 1.0 / (2.0 * i + 1.0);

        if (i % 2 == 0)
            pi_approximation += term;
        else
            pi_approximation -= term;
    }

    pi_approximation *= 4.0;
    return pi_approximation;
}

int main(int argc, char* argv[]) {
    double pi_approximation = approx_pi(10000000);
    printf("%f\n", pi_approximation);

    return EXIT_SUCCESS;
}
