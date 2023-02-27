#include <ncurses.h>
#define BRED "41m"
#define D_FGREEN "\033[6;"
int main()
{
    initscr();
    cbreak();
    //noecho();
    //halfdelay(10);
    //nodelay(stdscr,true);
    //timeout(10);
    /*int c;
    while((c=getch())!='x')
    {
        printw("%d\n",c);
    }
    */
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);

    attr_t emphasis=(A_REVERSE | COLOR_PAIR(1));
    attron(A_REVERSE | COLOR_PAIR(2));
    printw("heloo\n");
    attroff(A_REVERSE | COLOR_PAIR(2));
    attron(emphasis);
    printw("Bye");
    attroff(emphasis);
    getch();
    endwin();
    return 0;
 }
