#ifndef VIEW_HPP
#define VIEW_HPP

#include<ncurses.h>

struct View
{   
    int termX,termY;
    int mainWindowHeight;
    int mainWindowWidth;

    WINDOW* mainWindow = newwin(termY-1,termX-1,0,0);


    void render();
};




#endif