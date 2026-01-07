#include "view.hpp" 
void View::render(){ 
    //get the window ready and resizable 
    termX = getmaxx(stdscr);//terminal width 
    termY = getmaxy(stdscr);//terminal height 
    mainWindowHeight = termY; 
    mainWindowWidth = termX; 
    
    wresize(mainWindow,mainWindowHeight-1,mainWindowWidth-1); 
    wclear(mainWindow);
    box(mainWindow,0,0);
    
    wrefresh(mainWindow);
    refresh(); 

}