#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"

int main()
{
    initscr();
    //int y,x,;
    //int yBeg,xBeg;
    int yMax,xMax;
    cbreak();
    noecho();
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
    init_pair(1, COLOR_RED, COLOR_BLACK);
    getmaxyx(stdscr,yMax,xMax);

    //WINDOW *inputwin=newwin(3,xMax-12,yMax-5,5);
    WINDOW *inputwin=newwin(3,xMax-12,yMax-5,5);
    box(inputwin,0,0);
    refresh();
    wrefresh(inputwin);
    //chtype ch='a';
    keypad(inputwin,true);
    scrollok(inputwin,true);
    wmove(inputwin,1,1);
    while(true){
        wprintw(inputwin,"you pressed UP!");
        wrefresh(inputwin);
    }
    int c = wgetch(inputwin);
    //if(c == 'j')
    //if(c == KEY_UP)
    if(c == KEY_F(1))
    {
    //echo();
        mvwprintw(inputwin,2,1,"you pressed UP");
        wrefresh(inputwin);
    }
    //getyx(stdscr,y,x);
    //getbegyx(inputwin,yBeg,xBeg);
    //printw("%d %d %d %d %d %d\n",y,x,yBeg,xBeg,yMax,xMax);
    //mvprintw(yMax/2,xMax/2,"%d %d",yBeg,xBeg);
    refresh();
    getch();
    endwin();
    //return 0;
}
