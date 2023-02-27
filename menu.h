#include<ncurses.h>
#include<string.h>

#ifndef _MENU_H_
#define _MENU_H_
struct menu{
    int start_x;
    char text[20];
    cahr trigger;

};
struct menubar{
    WINDOW *win;
    menu *menus;
    int num_menus;
}


