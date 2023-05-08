#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, prev = 0, i = -1;
    int state = OUT;
    int buffer[64];
    int max = 0, count = 0;

    while ((c = getchar()) != EOF) {
        if (state == OUT && c != ' ' && c != '\n' && c != '\t') {
            i++;
            buffer[i] = 1;
            state = IN;
            count++;
            if (buffer[i] > max) max = buffer[i];
        } else if (state == IN && c != ' ' && c != '\n' && c != '\t') {
            buffer[i]++;
            if (buffer[i] > max) max = buffer[i];
        } else state = OUT;
    }

    for (int i = max; i >= 1; i--) {
        for (int j = 0; j < count; j++) {
            if (buffer[j] >= i) printf("# ");
            else printf("  ");
        }
        printf("\n");
    }

    return 0;
}
