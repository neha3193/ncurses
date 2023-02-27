#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"

int main()
{
    initscr();
    int x,y,c;
    x=y=10;
    move(y,x);
    printw("hell0");
    c = getch();
    //move(0,0);
    clear();
    mvprintw(0,0,"%d",c);
    refresh();
    getch();
    endwin();
    //return 0;
}
