#include <stdio.h>

#define MAXLENGTH 100

int main() {
    char s[MAXLENGTH];
    int i = 0;

    while (i < MAXLENGTH) {
        char c = getchar();

        if (c == EOF) break;
        else if (c == '\n') break;

        s[i] = c;
        i++;
    }

    printf("%s\n", s);

    return 0;
}
