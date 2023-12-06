#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAXLEN 1024

#define RANGES 7

typedef struct Range {
    unsigned long dest;
    unsigned long source;
    unsigned long length;
} Range;

static unsigned 
count_seeds(FILE* input, char buffer[], unsigned size);

static void 
fill_ranges_count(unsigned ranges_count[], FILE* input, char buffer[], unsigned size);

static void 
fill_seeds(unsigned seeds_count, unsigned long seeds[seeds_count], FILE* input, char buffer[], unsigned size);

static void
fill_ranges(Range** ranges[], unsigned ranges_count[], FILE* input, char buffer[], unsigned size);

static void
free_ranges(Range** ranges[], unsigned length);

static unsigned long 
map(Range* r[], unsigned long num); 

int 
main(int argc, char* argv[])
{
    FILE* input = fopen("input", "r");
    char buffer[MAXLEN];

    unsigned seeds_count = count_seeds(input, buffer, MAXLEN);
    unsigned ranges_count[RANGES] = { 0 };
    fill_ranges_count(ranges_count, input, buffer, MAXLEN);

    Range** ranges[RANGES];
    unsigned long seeds[seeds_count];

    rewind(input);

    fill_seeds(seeds_count, seeds, input, buffer, MAXLEN);
    fill_ranges(ranges, ranges_count, input, buffer, MAXLEN);

    fclose(input);

    unsigned long lowest = ULONG_MAX;
    for (unsigned i = 0; i < seeds_count; i+= 2) {
        for (unsigned seed = seeds[i]; seed < seeds[i] + seeds[i + 1]; seed++) {
            unsigned long num = seed;
            for (unsigned range = 0; range < sizeof(ranges) / sizeof(ranges[0]); range++)
                num = map(ranges[range], num);

            if (num < lowest) lowest = num;
        }

    }

    printf("%ld\n", lowest);

    free_ranges(ranges, RANGES);
    return 0;
}

static unsigned 
count_seeds(FILE* input, char buffer[], unsigned size)
{
    unsigned seeds = 0;

    fgets(buffer, MAXLEN, input);
    for (char* ptr = buffer; (ptr = strchr(ptr, ' ')) != NULL; seeds++)
        ptr++;
    
    return seeds;
}

static void 
fill_ranges_count(unsigned ranges_count[], FILE* input, char buffer[], unsigned size)
{
    for (unsigned i = -1; fgets(buffer, MAXLEN, input);) {
        if (isdigit(buffer[0])) ranges_count[i]++;
        else if (buffer[0] != '\n') i++;
    }
}

static void 
fill_seeds(unsigned seeds_count, unsigned long seeds[seeds_count], FILE* input, char buffer[], unsigned size)
{
    fgets(buffer, size, input);
    strtok(buffer, " ");
    for (unsigned i = 0; i < seeds_count; i++)
        seeds[i] = atol(strtok(NULL, " "));

    rewind(input);
}

static void
fill_ranges(Range** ranges[], unsigned ranges_count[], FILE* input, char buffer[], unsigned size)
{
    fgets(buffer, size, input);

    for (int range = -1, range_indx = 0; fgets(buffer, size, input);) {
        if (isdigit(buffer[0])) {
            Range* r = (Range*) malloc(sizeof(Range));
            sscanf(buffer, "%ld %ld %ld\n", &r->dest, &r->source, &r->length);

            ranges[range][range_indx++] = r;
        } else if (buffer[0] != '\n') {
            if (range >= 0)
                ranges[range][range_indx] = NULL;

            range++;
            range_indx = 0;

            ranges[range] = (Range**) malloc(sizeof(Range) * ranges_count[range] + 1);
        }
    }

    rewind(input);

}

static void
free_ranges(Range** ranges[], unsigned length)
{
    for (unsigned i = 0; i < length; i++) {
        for (unsigned j = 0; ranges[i][j] != NULL; j++)
            free(ranges[i][j]);
        free(ranges[i]);
    }
}

static unsigned long
map(Range* r[], unsigned long num) 
{
    for (unsigned i = 0; r[i] != NULL; i++) {
        if (num >= r[i]->source && num < r[i]->source + r[i]->length)
            return num - (r[i]->source - r[i]->dest);
    }

    return num;
}
