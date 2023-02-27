
#include <panel.h>
#include <string.h>

typedef struct _PANEL_DATA {
    int hide;   /* TRUE if panel is hidden */
}PANEL_DATA;

#define NLINES 10
#define NCOLS 40

void init_wins(WINDOW **wins, int n);
void win_show(WINDOW *win, char *label, int label_color);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int main()
{   WINDOW *my_wins[3];
    PANEL  *my_panels[3];
    PANEL_DATA panel_datas[3];
    //PANEL_DATA *tempA,*tempB,*tempC;
    int ch;
    // int height, width;
    // getmaxyx(stdscr, height, width);
    /* Initialize curses */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    init_wins(my_wins, 3);

    /* Attach a panel to each window */     /* Order
                                               is bottom up */
    my_panels[0] = new_panel(my_wins[0]);   /* Push 0, order: stdscr-0 */
    my_panels[1] = new_panel(my_wins[1]);   /* Push 1, order: stdscr-0-1 */
    my_panels[2] = new_panel(my_wins[2]);   /* Push 2, order: stdscr-0-1-2 */

    /* Initialize panel datas saying
     * that nothing is hidden */
    panel_datas[0].hide = FALSE;
    panel_datas[1].hide = FALSE;
    panel_datas[2].hide = FALSE;

    set_panel_userptr(my_panels[0], &panel_datas[0]);
    set_panel_userptr(my_panels[1], &panel_datas[1]);
    set_panel_userptr(my_panels[2], &panel_datas[2]);
    char label[] = "new";
    /* Update
     * the
     * stacking
     * order.
     * 2nd
     * panel
     * will
     * be
     * on
     * top
     * */
    update_panels();

    /* Show
     * it
     * on
     * the
     * screen
     * */
    attron(COLOR_PAIR(4));
    mvprintw(LINES - 3, 0, "Show or Hide a window with 'a'(first window)  'b'(Second Window)  'c'(Third Window)");
    mvprintw(LINES - 2, 0, "F1 to Exit");

    attroff(COLOR_PAIR(4));
    doupdate();
    //tempA = (PANEL_DATA *)panel_userptr(my_panels[0]);
    //tempB = (PANEL_DATA *)panel_userptr(my_panels[1]);
    //tempC = (PANEL_DATA *)panel_userptr(my_panels[2]);
    show_panel(my_panels[0]);
    show_panel(my_panels[1]);
    show_panel(my_panels[2]);
    int i=0;
    update_panels();
    doupdate();

    while((ch = getch()) != KEY_F(1))
    {   switch(ch)
        {   case 'a':
            touchwin(stdscr);
            //tempB->hide = TRUE;
            //tempC->hide = TRUE;
            my_wins[0] = newwin( 32, 149 ,0,0);
            win_show(my_wins[0], label, i + 1);
            wrefresh(my_wins[0]);
            break;
            case 'b':
            touchwin(stdscr);
            //tempA->hide = TRUE;
            //tempC->hide = TRUE;
            my_wins[1] = newwin( 32, 149 ,0,0);
            win_show(my_wins[1], label, i + 1);
            wrefresh(my_wins[1]);
            break;
            case 'c':
            touchwin(stdscr);
            //tempB->hide = TRUE;
            //tempC->hide = TRUE;
            my_wins[2] = newwin( 32, 149 ,0,0);
            win_show(my_wins[2], label, i + 1);
            wrefresh(my_wins[2]);
            break;
            case 'q':
            touchwin(stdscr);
            init_wins(my_wins, 3);
            for(i=0;i<3;i++){
                wrefresh(my_wins[i]);
                show_panel(my_panels[i]);
            }
            break;

        }
        update_panels();
        doupdate();
    }
    endwin();
    return 0;
}

/* Put all the windows */
void init_wins(WINDOW **wins, int n)
{   int x, y, i;
    char label[80];

    y = 2;
    x = 10;
    for(i = 0; i < n; ++i)
    {   wins[i] = newwin(NLINES, NCOLS, y, x);
        sprintf(label, "Window Number %d", i + 1);
        win_show(wins[i], label, i + 1);
        y += 3;
        x += 7;
    }
}

/* Show the window with a border and a label */
void win_show(WINDOW *win, char *label, int label_color)
{ 
    // int startx, starty,i
    int height, width;

    //getbegyx(win, starty, startx);
    getmaxyx(win, height, width);
    printf("%d",height);
    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE); 
    mvwhline(win, 2, 1, ACS_HLINE, width - 2); 
    mvwaddch(win, 2, width - 1, ACS_RTEE); 

    print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{   int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}
