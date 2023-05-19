#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char s[] = "   -3324.3566e-2.5";
    double n = atof(s);

    printf("%f\n", n);
    return 0;
}

double atof(char s[]) {
    double val, power, exp, exp_power;
    int i, sign, exp_sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');

    if (s[i] == '.') i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E') i++;
    exp_sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;

    for (exp = 0.0; isdigit(s[i]); i++)
        exp = exp * 10.0 + (s[i] - '0');

    if (s[i] == '.') i++;
    for (exp_power = 1.0; isdigit(s[i]); i++) {
        exp = exp * 10.0 + (s[i] - '0');
        exp_power *= 10.0;
    }

    return (sign * val / power) * pow(10, (exp / exp_power) * exp_sign);
}
