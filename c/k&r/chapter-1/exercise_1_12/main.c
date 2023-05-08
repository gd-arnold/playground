#include <stdio.h>

int main() {
    int c, prev;

    while ((c = getchar()) != EOF) {
        if (prev != '\n' && (c == ' ' || c == '\t' || c == '\n')) {
            putchar('\n');
            prev = '\n';
        } else if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
            prev = c;
        }

    }

    return 0;
}
