#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<menu.h>
int yMax,xMax,yBeg,xBeg,i,choice,highlite=0;
char ch;
char str[3][4]={"opt1","opt2","opt3"};
WINDOW *win; 
void inter()
{
    box(win,0,0);
    mvwprintw(win,0,2,"File");
    mvwprintw(win,0,7,"Edit");
    mvwprintw(win,0,12,"Options");
    keypad(win,true);
    wrefresh(win);
    while(1)
    {
        ch = wgetch(win);
        switch(ch)
        {
            case 'f':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
                //printsubmenu();
                break;
            case 'e':
                mvwprintw(win,0,2,"File");
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,12,"Options");
                break;
            case 'o':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,12,"Options");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
                break;
            default:
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
                break;

        }
    }

}
void printsubmenu()
{
    WINDOW *inputwin = newwin(yMax-2,xMax-2,yBeg+1,xBeg+1);
    keypad(inputwin,true);
    wrefresh(inputwin);
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
                //clear();
                werase(inputwin);
                //getch();
                return;
        }
    }

}
void printmainmenu()
{
//A:
    box(win,0,0);
    mvwprintw(win,0,2,"File");
    mvwprintw(win,0,7,"Edit");
    mvwprintw(win,0,12,"Options");
    keypad(win,true);
    wrefresh(win);
    while(1)
    {
        ch = wgetch(win);
        switch(ch)
        {
            case 'f':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
                wrefresh(win);
                printsubmenu(); 
                refresh();
                //goto A;
                wrefresh(win);
                break;
            case 'e':
                mvwprintw(win,0,2,"File");
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,12,"Options");
                break;
            case 'o':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,12,"Options");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
                break;
            default:
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
                break;

        }
    }

}

int main(){
    initscr();
    noecho();
    curs_set(0);
    getmaxyx(stdscr,yMax,xMax);
    refresh();
    //WINDOW *win = newwin(yMax/2,xMax/2,yMax/4,xMax/4);
    win = newwin(yMax-5,xMax-5,yMax/16,xMax/150);
    getbegyx(win,yBeg,xBeg);
    wrefresh(win);
    printmainmenu();
    //wrefresh(win);
    //wgetch(win);
    endwin();
    return 0;
}
