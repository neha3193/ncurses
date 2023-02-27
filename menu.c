#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"
struct Player
{
    int xLoc,yLoc,xMax,yMax;
    char character;
    WINDOW* curwin;
}
struct Player* player(WINDOW *win, int y,int x,char c)
{
    struct Player *p;
    p->curwin = win;
    p->yLoc=y;
    p->xLoc=x;
    getmaxyx(p->curwin,p->yMax,p->xMax);
    keypad(p->curwin,true);
    p->character =c;
    return p;
}
void mvup()
{
    
}
void mvdown()
{
}
void mvleft()
{
}
void mvright()
{
}
int getmv()
{
}
void display()
{
}
int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();
    int xMax,yMax,i,choice,highlite=0;
    getmaxyx(stdscr,yMax,xMax);
    xMax=50;
    WINDOW *inputwin=newwin(20,xMax,(yMax/2)-10,10);
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
