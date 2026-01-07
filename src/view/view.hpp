#ifndef VIEW_HPP
#define VIEW_HPP

#include<ncurses.h>

struct View
{   
    int termX,termY;
    int mainWindowHeight;
    int mainWindowWidth;

    WINDOW* mainWindow = newwin(30,30,0,0);

    void render();
};




#endif