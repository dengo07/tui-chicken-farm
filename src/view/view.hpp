#ifndef VIEW_HPP
#define VIEW_HPP

#include<ncurses.h>
#include<vector>
#include "../models/models.hpp"

struct View
{   
    int termX,termY;
    int mainWindowHeight;
    int mainWindowWidth;

    WINDOW* mainWindow = newwin(30,30,0,0);

    void render(std::vector<Chicken*>*,std::vector<Food*>*,int);
};




#endif