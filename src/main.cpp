#include<ncurses.h>
#include "view/view.hpp"

void initialize(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

}

int main(){
    initialize();
    View view;
    view.render(); 
    return 0;
}