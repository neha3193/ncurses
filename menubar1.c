#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#define ctrl(x) (x & 0x1F)

int main(){
    initscr();
    char ch;
    noecho();
    curs_set(0);
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);
    printw("%d,%d",yMax,xMax);
    refresh();
    //WINDOW *win = newwin(yMax/2,xMax/2,yMax/4,xMax/4);
    WINDOW *win = newwin(yMax-5,xMax-5,yMax/16,xMax/150);
    box(win,0,0);
    mvwprintw(win,0,2,"File");
    mvwprintw(win,0,7,"Edit");
    mvwprintw(win,0,12,"Options");
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
    //wrefresh(win);
    wgetch(win);
    endwin();
    return 0;
}
