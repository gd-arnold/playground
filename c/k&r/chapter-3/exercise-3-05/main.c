#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itob(unsigned n, char s[], unsigned b);
char dtoc(unsigned n);
void reverse(char s[]);

int main() {
    char s[MAXLEN];
    unsigned int n = 255;
    unsigned int b = 16;

    itob(n, s, b);
    printf("%s\n", s);
    return 0;
}

void itob(unsigned n, char s[], unsigned b) {
    int i = 0;

    do {
        s[i++] = dtoc(n % b);
    } while(n /= b);

    s[i] = '\0';
    reverse(s);
}

char dtoc(unsigned n) {
    if (n < 10) return '0' + n;

    return 'A' + n - 10;
}

void reverse(char s[]) {
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
