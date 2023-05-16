#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s[] = "jsrudpooo lbritrrrrchkjjjers";
    squeeze(s, "rljdko");

    printf("%s\n", s);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (int p = 0; s2[p] != '\0'; p++) {
            if (s2[p] == s1[i]) goto skip;
        }

        s1[j++] = s1[i];
        skip:;
    }
    s1[j] = '\0';
}
