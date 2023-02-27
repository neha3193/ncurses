#include <ncurses.h>
#define BRED "41m"
//#define COLOR_RED "41m"
#define D_FGREEN "\033[6;"

int main()
{
    initscr();
    int y,x,yBeg,xBeg,yMax,xMax;
    /*
     * COLOR_BLACK
     * COLOR_RED
     * COLOR_GREEN
     * COLOR_YELLOW
     * COLOR_BLUE
     * COLOR_MAGENTA
     * COLOR_CYAN
     * COLOR_WHITE
     */
    start_color();
//    init_pair(1, COLOR_BLUE, COLOR_WHITE);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    printw("hell0");
    attroff(COLOR_PAIR(1));
    WINDOW *win=newwin(10,20,10,20);
    refresh();
    getyx(stdscr,y,x);
    getbegyx(win,yBeg,xBeg);
    getmaxyx(stdscr,yMax,xMax);
    printw("%d %d %d %d %d %d\n",y,x,yBeg,xBeg,yMax,xMax);
    mvprintw(yMax/2,xMax/2,"%d %d",yBeg,xBeg);
    refresh();
    getch();
    endwin();
    //return 0;
}
