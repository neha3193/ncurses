#include <curses.h>

int main()
{
    initscr();
    int yMax,xMax;
    printw("Main window");
    getmaxyx(stdscr,yMax,xMax);
    mvprintw(9,0,"%d %d",yMax,xMax);
    WINDOW* subwindow = newwin(10,20,5,15);

    refresh();

    box(subwindow,0,0);
    mvwprintw(subwindow, 1, 1, "subwindow");


    refresh();
    wrefresh(subwindow);

    getch();
    delwin(subwindow);

    endwin();
    return 0;
}

