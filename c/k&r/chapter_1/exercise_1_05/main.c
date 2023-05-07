#include <stdio.h>

int main() {
    const int lower = 0, upper = 300, step = 20;

    printf("======================\n");
    for (float fahr = upper; fahr >= lower; fahr-=step) {
        float celsius = (5.0 / 9) * (fahr - 32);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    }
}
