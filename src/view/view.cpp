#include "view.hpp" 
void View::render(std::vector<Chicken*>* chickens,std::vector<Food*>* foods ){ 
    //get the window ready and resizable 
    termX = getmaxx(stdscr);//terminal width 
    termY = getmaxy(stdscr);//terminal height 
    mainWindowHeight = termY; 
    mainWindowWidth = termX; 

    wresize(mainWindow,mainWindowHeight-1,mainWindowWidth-1); 
    wclear(mainWindow);
    box(mainWindow,0,0);
    
    if(!(chickens->empty())){
        for(int i = 0; i < chickens->size();i++){
            //Printing foods on to screen
            mvwprintw(mainWindow,chickens->at(i)->position[1],chickens->at(i)->position[0],chickens->at(i)->art.c_str());            
        }
    }

    if(!(foods->empty())){
        for(int i = 0; i < foods->size();i++){
            //Printing foods on to screen
            mvwprintw(mainWindow,foods->at(i)->position[1],foods->at(i)->position[0],foods->at(i)->art.c_str());
        }
    }

    wrefresh(mainWindow);
    refresh(); 

}