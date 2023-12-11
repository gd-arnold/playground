#include <curses.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 100000

int
main(int argc, char* argv[])
{
    WINDOW* win = initscr();

    keypad(win, true);
    nodelay(win, true);

    int8_t pos_x, pos_y, dir_x, dir_y, food_x, food_y;

    pos_x = pos_y = dir_x = 1;
    dir_y = 0;
    food_x = rand() % 20;
    food_y = rand() % 20;

    while (true) {
        uint16_t pressed = wgetch(win);

        switch (pressed) {
            case KEY_LEFT:
                dir_x = -1;
                dir_y = 0;
                break;
            case KEY_RIGHT:
                dir_x = 1;
                dir_y = 0;
                break;
            case KEY_UP:
                dir_x = 0;
                dir_y = -1;
                break;
            case KEY_DOWN:
                dir_x = 0;
                dir_y = 1;
                break;
        }

        erase();

        pos_x += dir_x;
        pos_y += dir_y;

        mvaddstr(pos_y, pos_x, "*");
        mvaddstr(food_y, food_x, "&");

        if (pos_x == food_x && pos_y == food_y) {
            food_x = rand() % 20;
            food_y = rand() % 20;
        }

        usleep(DELAY);
    }

    endwin();
    return 0;
}
