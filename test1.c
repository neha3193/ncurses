#include <ncurses.h>

int main(void)
{

    WINDOW *p;
    initscr();

int row=5;
        p = newpad(10, 10);
    scrollok(p, TRUE);

    while(1)
    {
        waddstr(p, "newww");   /* text_buffer is continuously refreshing */
        prefresh(p, row, 0, 0, 0, 20, 20);

        switch(wgetch(p))
        {
            case KEY_UP:
                row -= 2;
                if(row < 0) row = -1;
                break;

            case KEY_DOWN:
                row += 1;
                if(row > 20) v->row = 20;
                break;
        }
    }

    /*
       new = newpad(120,120);
       WINDOW *orig, *mypad;
       orig = newpad(100, 200);
       mypad = subpad(orig, 30, 5, 25, 180);
    //  getmaxyx(stdscr, height, width);
    new = newwin(height - 2, width - 2, 1, 1);
    new1 = newwin(height, width, 1, 1);
    box(new1,1,1);
    wrefresh(new1);
    ++i;
    scrollok(new,TRUE);
    while(1)
    {
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        ++i;
        mvwprintw(new,i,0, "%d \n", i);
        //wrefresh(new);
        prefresh (new, 0,0,0,0,20,30);


    }

    */
    endwin();
    return 0;
}
