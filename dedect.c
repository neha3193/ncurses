#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#define ctrl(x) (x & 0x1F)

int main(){
    initscr();
    char ch;
    noecho();
    while(1)
    {
     (ch = getch());
        mvprintw(1,0,"KEY_NAME :%c %x", (ch),ch);
        if(ch == ctrl('A'))
            mvprintw(0,0,"dedected cntl+a!");
    }
    endwin();
    return 0;
}
