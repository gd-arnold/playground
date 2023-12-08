#include <stdio.h>
#include <math.h>

int
main(int argc, char* argv[])
{
    unsigned long time = 60808676;
    unsigned long distance = 601116315591300;

    float discriminant = time * time - 4 * distance;
    unsigned x1 = floor(((time - sqrt(discriminant)) / 2) + 1);
    unsigned x2 = ceil(((time + sqrt(discriminant)) / 2) - 1);

    unsigned res = x2 - x1 + 1;

    printf("%d\n", res);

    return 0;
}
