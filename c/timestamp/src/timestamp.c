#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "timestamp.h"
#include "dbg.h"


Timestamp* new_timestamp(uint8_t hours, uint8_t minutes)
{
    Timestamp* time = (Timestamp*) malloc(sizeof(Timestamp));
    time->hours = hours;
    time->minutes = minutes;

    return time;
}

void read_timestamp(Timestamp* time)
{
    char* buffer = NULL;
    size_t buffer_len = 0;
    uint8_t hours, minutes;
    hours = minutes = -1;

    check(getline(&buffer, &buffer_len, stdin) > 0, "Error reading input.");
    check(sscanf(buffer, "%hhd:%hhd", &hours, &minutes) > 0, "Invalid time format.");

    check(hours >= 0 && hours <= 23, "Invalid hours.");
    check(minutes >= 0 && minutes <= 60, "Invalid minutes.");

    time->hours = hours;
    time->minutes = minutes;

    free(buffer);
    return;

error:
    free(buffer);
    free(time);
    exit(EXIT_FAILURE);
}

Timestamp* add_timestamps(Timestamp* t1, Timestamp* t2)
{
    uint8_t hours_sum = t1->hours + t2->hours;
    uint8_t mins_sum = t1->minutes + t2->minutes;

    if (mins_sum > 60)
        hours_sum++;

    return new_timestamp(hours_sum % 24, mins_sum % 60);
}

void print_timestamp(Timestamp* time)
{
    printf("%s%hhd:%s%hhd\n",
           time->hours <= 9 ? "0" : "",
           time->hours,
           time->minutes <= 9 ? "0" : "",
           time->minutes);
}