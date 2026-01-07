#include "controller.hpp"


void Controller::run(View& view){
    int ch;
     while((ch = getch()) != 'q')
    {
        view.render();
        
    }
    
}