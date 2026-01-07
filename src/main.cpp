#include<ncurses.h>
#include "view/view.hpp"
#include "controller/controller.hpp"

void initialize(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(0);
    timeout(60);

}

int main(){
    initialize();
    View view;
    
    std::vector<Chicken*> chickens;
    std::vector<Food*> foods;
    Controller controller(&view,&chickens,&foods);

    controller.run();
    return 0;
}