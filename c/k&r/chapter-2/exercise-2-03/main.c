#include <stdio.h>
#include <ctype.h>
#include <math.h>

int htoi(char s[]);
int hexlen(char s[]);
int hctoi(char c);

int main() {
    int a = htoi("0xF40cBa");

    printf("%d\n", a);
    return 0;
}

int htoi(char s[]) {
    int len = hexlen(s);
    int n = 0;

    int start = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) start = 2;

    for (int i = start; i < len + start; i++) {
        int d = hctoi(s[i]);
        n += d * pow(16, len - 1 - i + start);
    }

    return n;
}

int hexlen(char s[]) {
    int len = 0;
    int start = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) start = 2;
    for (int i = start; s[i] != '\0'; i++) len++;

    return len;
}

int hctoi(char c) {
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    else if (c >= 'A' && c <= 'F') return 10 + c - 'A';

    return c - '0';
}
