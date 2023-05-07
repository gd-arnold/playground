#include <stdio.h>

int main() {
    int nb = 0, nt = 0, nl = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') nb++;
        else if (c == '\t') nt++;
        else if (c == '\n') nl++;
    }

    printf("Blanks count: %d\n", nb);
    printf("Tabs count: %d\n", nt);
    printf("Lines count: %d\n", nl);

    return 0;
}
