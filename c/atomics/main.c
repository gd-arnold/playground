#include <stdio.h>
#include <stdatomic.h>

atomic_int count = ATOMIC_VAR_INIT(0);

void increment_count()
{
    atomic_fetch_add(&count, 1);
}

int get_count()
{
    return atomic_load(&count);
}

int main(int argc, char **argv)
{
    for (size_t i = 0; i < 5; i++)
        increment_count();

    printf("%d\n", get_count());
}