#include <ncurses.h>

int main()
{
    char text[5];// = "This is some wrapping. \n";
    int x;

    initscr();

    scrollok(stdscr,TRUE);
    for(x=0;x<1000;x++)
    {
        sprintf(text,"%d\n",x);
        addstr(text);
        napms(100);
        refresh();
    }   
    getch();

    endwin();
    return(0);
}
