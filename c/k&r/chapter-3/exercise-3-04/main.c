#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa(int n, char s[]);
void reverse(char s[]);
int absv(int n);

int main() {
    char s[MAXLEN];

    itoa(-34325, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]) {
    int i = 0, sign = n, remd;

    do {
        s[i++] = '0' + absv(n % 10);
    } while (n /= 10);

    if (sign < 0) s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int absv(int n) {
    return n < 0 ? -1 * n : n;
}
