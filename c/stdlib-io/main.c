#include <stdint.h>
#include <stdio.h>

#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
} EyeColor;

const char* EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    uint16_t age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
} Person;

int main(int argc, char* argv[])
{
    Person you = { you.age = 0 };
    uint16_t rc = 0;
    char* in = NULL;

    printf("What's your first name?\n");
    in = fgets(you.first_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first name.");

    printf("What's your last name?\n");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first name.");

    printf("How old are you?\n");
    rc = scanf("%hd", &you.age); 
    check(rc > 0, "You have to enter a number.");

    printf("What color are your eyes?\n");
    for (uint8_t i = 0; i <= OTHER_EYES; i++)
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    printf("> ");

    uint16_t eyes = 0;
    rc = scanf("%hd", &eyes);
    check(rc > 0, "You have to enter a number.");
    check(eyes >= 1 && eyes <= OTHER_EYES + 1, "Do it right, that's not an option.");
    you.eyes = eyes - 1;

    printf("----RESULTS----\n");

    printf("First name: %s", you.first_name);
    printf("Last name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eye color: %s\n", EYE_COLOR_NAMES[you.eyes]);

    return 0;
error:
    return -1;
}
