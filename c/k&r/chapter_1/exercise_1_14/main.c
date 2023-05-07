#include <stdio.h>

#define CHAR_COUNT 256

int main() {
    int buffer[CHAR_COUNT];
    int c, largest = 0;

    for (int i = 0; i < CHAR_COUNT; i++)
        buffer[i] = 0;

    while ((c = getchar()) != EOF) {
        buffer[c]++;
        if (buffer[c] > largest) largest = buffer[c];
    }

    for (int i = largest; i > 0; i--) {
        for (int j = 0; j < CHAR_COUNT; j++) {
            if (buffer[j] >= i) printf("# ");
            else if (buffer[j] > 0) printf("  ");
        }
        printf("\n");
    }

    return 0;
}
