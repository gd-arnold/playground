#include <stdio.h>

#define MINLINE 80

int main() {
    char line[MINLINE];
    int i = 1;
    int c;

    while (i > 0) {
        for (i = 0; (c = getchar()) != EOF; i++) {
            if (i < MINLINE) line[i] = c;
            else if (i == MINLINE) {
                printf("%s", line);
                putchar(c);
            }
            else putchar(c);

            if (c == '\n') {
                i++;
                break;
            }
        }
    }

    return 0;
}
