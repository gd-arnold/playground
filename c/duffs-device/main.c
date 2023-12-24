#include <stdint.h>
#include <stdbool.h>

#include "dbg.h"

bool is_copy_valid(const char data[], uint32_t count, char expected)
{
    for (uint32_t i = 0; i < count; i++)
        if (data[i] != expected)
            return false;

    return true;
}

uint32_t normal_copy(const char from[], char to[], uint32_t count)
{
    uint32_t i;

    for (i = 0; i < count; i++)
        to[i] = from[i];

    return i;
}

uint32_t duffs_device(const char from[], char to[], uint32_t count)
{
    {
        uint32_t n = (count + 7) / 8; // 125

        switch (count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while (--n > 0);
        }
    }

    return count;
}

int main(int argc, char* argv[])
{
    char from[1000];
    memset(from, 'x', 1000);
    char to[1000];
    memset(to, 'y', 1000);

    uint32_t rc;

    // normal copy
    rc = normal_copy(from, to, 1000);
    check(rc == 1000, "Normal copy failed: %d", rc);
    check(is_copy_valid(to, 1000, 'x'), "Normal copy failed.");

    // reset
    memset(to, 'y', 1000);

    // duff's device
    rc = duffs_device(from, to, 1000);
    check(rc == 1000, "Normal copy failed: %d", rc);
    check(is_copy_valid(to, 1000, 'x'), "Normal copy failed.");

    return 0;
error:
    return 1;
}
