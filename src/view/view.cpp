#include "view.hpp" 
void View::render(std::vector<Chicken*>* chickens,std::vector<Food*>* foods,int gameSpeed){ 
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

    //print stats(speed of game and chicken count)
    mvprintw(termY-1, 0,  "Chicken Count: %4zu", chickens->size());
    mvprintw(termY-1, 20, "Food Count: %4zu", foods->size());
    mvprintw(termY-1, 40, "Game Speed: %3d", 110 - gameSpeed);

    wrefresh(mainWindow);
    refresh(); 

}