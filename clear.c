#include<ncurses.h>

int main()
{
    initscr();
    refresh();
    printw("hello");
   // getch();
    getch();
    move(1,1);
    printw("hello");
    move(0,1);
    clrtoeol();
    getch();
    endwin();
    return 0;
    

}
