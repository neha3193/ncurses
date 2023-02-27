#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"

int main()
{
    initscr();
    cbreak(); 
    //raw();
    nocbreak(); 
    int h,w,start_y,start_x,left,right,top,bottom,tlc,trc,blc,brc;
    h=10;
    w=30;
    start_y=start_x=10;
    left=right=top=bottom=tlc=trc=blc=brc=100;
    WINDOW *win= newwin(h,w,start_y,start_x);
    refresh();
    //box(win,0,0);
    wborder(win,left,right,top,bottom,tlc,trc,blc,brc);
    //start_ncurses(true,true);
    mvwprintw(win,1,2,"BOX");
    attron(A_STANDOUT);
    printw("new");
    attroff(A_STANDOUT);
    wrefresh(win);
    getch();
    getch();
    endwin();
    //return 0;
}
