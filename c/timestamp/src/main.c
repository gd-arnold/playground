#include <stdio.h>
#include <stdlib.h>

#include "timestamp.h"

int main(int argc, char* argv[])
{
    Timestamp* start_time = new_timestamp(0, 0);
    Timestamp* delta_time = new_timestamp(0, 0);

    printf("Enter start time (hh:mm) > ");
    read_timestamp(start_time);

    printf("Enter delta time (hh:mm) > ");
    read_timestamp(delta_time);

    Timestamp* end_time = add_timestamps(start_time, delta_time);

    printf("End time: ");
    print_timestamp(end_time);

    free(start_time);
    free(delta_time);
    free(end_time);

    exit(EXIT_SUCCESS);
}