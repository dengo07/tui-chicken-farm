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
    std::string title1 = "Chicken Count: "+std::to_string(chickens->size());
    std::string title2 = "Food Count: "+std::to_string(foods->size());
    std::string title3 = "Game Speed: "+std::to_string(110-gameSpeed);
    mvprintw(termY-1,0,title1.c_str());
    mvprintw(termY-1,20,title2.c_str());
    mvprintw(termY-1,40,title3.c_str());

    wrefresh(mainWindow);
    refresh(); 

}