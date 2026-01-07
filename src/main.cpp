#include<ncurses.h>
#include "view/view.hpp"
#include "controller/controller.hpp"

void initialize(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);

}

int main(){
    initialize();
    View view;
    Controller controller;
    controller.run(view);
    return 0;
}