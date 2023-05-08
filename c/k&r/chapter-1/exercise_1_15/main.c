#include <stdio.h>

float fahrToCels(float fahr);

int main() {
    float fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    printf("======================\n");

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = fahrToCels(fahr);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahrToCels(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}


