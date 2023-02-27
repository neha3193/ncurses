#include <ncurses.h>

int main()
{   
    int y,c;

    initscr();

    scrollok(stdscr,TRUE);
    for(y=0;y<=(LINES*2);y++)
        mvprintw(y,0,"Line %d",y);
    while((c = getch()) != KEY_F(1))
    {
        switch(c)
        {
            case KEY_NPAGE:
                menu_driver(stdscr, REQ_SCR_DPAGE);
                break;
            case KEY_PPAGE:
                menu_driver(stdscr, REQ_SCR_UPAGE);
                break;
        }
    refresh();
    }
        //
        //
        getch();

        scrl(3);
        refresh();
        getch();

        endwin();
        return(0);
}
