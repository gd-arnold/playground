#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 256

int
main(int argc, char* argv[])
{
    FILE* input = fopen("input", "r");
    char buffer[MAXLEN];

    unsigned times[4], distances[4];

    fgets(buffer, MAXLEN, input);
    sscanf(buffer, "Time: \t\t%d\t%d\t%d\t%d\n",
            &times[0], &times[1], &times[2], &times[3]);

    fgets(buffer, MAXLEN, input);
    sscanf(buffer, "Distance:\t%d\t%d\t%d\t%d\n",
            &distances[0], &distances[1], &distances[2], &distances[3]);

    unsigned res = 1;

    for (unsigned i = 0; i < 4; i++) {
        float discriminant = times[i] * times[i] - 4 * distances[i];
        unsigned x1 =  floor(((times[i] - sqrt(discriminant)) / 2) + 1);
        unsigned x2 = ceil(((times[i] + sqrt(discriminant)) / 2) - 1);

        res *= x2 - x1 + 1;
    }

    printf("%d\n", res);

    return 0;
}
