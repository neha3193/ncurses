#include <ncurses.h>

int main(void)
{
    initscr();
//    int maxy,maxx,y;'
    int y;
//    getmaxyx(stdscr,maxy,maxx);
    scrollok(stdscr,TRUE);
//printw("%d",maxx);
    for(y=0;y<=40;y++)
        mvprintw(y,0,"This is boring text written to line %d.",y);
    refresh();
    getch();
 scroll(stdscr);
    for(y=0;y<=40;y++)
        mvprintw(y,0,"This is boring text written to line %d.",y);
    scrl(3);
    refresh();
    getch();

    endwin();
    return(0);
}
