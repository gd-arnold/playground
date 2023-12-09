#include <stdio.h>

#include "z.h"

int xfn()
{
    return yfn(1);
}

int main()
{
   printf("%d\n", xfn());
    return 0;
}
