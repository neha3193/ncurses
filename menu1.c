#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"

int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();
    int xMax,yMax,i,choice,highlite=0;
    getmaxyx(stdscr,yMax,xMax);
    WINDOW *inputwin=newwin(6,xMax-12,yMax-8,5);
    box(inputwin,0,0);
    refresh();
    wrefresh(inputwin);
    keypad(inputwin,true);
    char str[3][4]={"opt1","opt2","opt3"};
    //mvwprintw(inputwin,1,1,"you need pressed UP");
    while(1)
    {
        for(i=0;i<3;i++)
        {
            if(i==highlite)
                wattron(inputwin,A_REVERSE);
            mvwprintw(inputwin,i+1,1,(str[i]));
            wattroff(inputwin,A_REVERSE);

        }
    choice = wgetch(inputwin);
    switch(choice)
    {   
        case KEY_UP:
            highlite--;
            if(highlite == -1)
                highlite=0;
            break;
        case KEY_DOWN:
            highlite++;
            if(highlite==3)
                highlite=2;
            break;
       default:
            break;
    }
    }
    refresh();
    getch();
    endwin();
    //return 0;
}
