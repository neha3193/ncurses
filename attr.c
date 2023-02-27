#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
int main()
{   initscr();          /* Start curses mode        */
    if(has_colors() == FALSE)
    {   endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();          /* Start color          */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    attron(COLOR_PAIR(1));

    print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
    printw("\nnew");
    attroff(COLOR_PAIR(1));
    chtype c= '@' | A_REVERSE |COLOR_PAIR(2);
    mvaddch(10,10,c);
    getch();
    endwin();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{   int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    mvwprintw(win, y, x, "%s", string);
    refresh();
}
