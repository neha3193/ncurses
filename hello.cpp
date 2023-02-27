#include<stdio.h>
#include <ncurses.h>

int main()
{
    initsrc();
    pritw("hell0");
    refresh();
    endwin();
}
