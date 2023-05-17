#include <stdio.h>

void lower(char s[]);

int main() {
    char s[] = "YABAdabaDUbDuB";
    lower(s);
    printf("%s\n", s);

    return 0;
}

void lower(char s[]) {
    const int diff = 'A' - 'a';

    for (int i = 0; s[i] != '\0'; i++)
        s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] - diff : s[i];
}
