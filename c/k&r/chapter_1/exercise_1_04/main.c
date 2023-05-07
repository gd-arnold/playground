#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower = -40, upper = 50, step = 10;

    printf("======================\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t\t%6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
