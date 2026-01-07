#include "controller.hpp"



Controller::Controller(View* v ,std::vector<Chicken*>* c,std::vector<Food*>* f){

    view = v;
    chickens = c;
    foods = f;
    

 }

void Controller::run(){
    int ch;
    MEVENT event;
     while((ch = getch()) != 'q')
    {
        for(int i = 0; i<chickens->size();i++){
            chickens->at(i)->updatePosition();
        }

        if (getmouse(&event) == OK) {
            int x = event.x;
            int y = event.y;

            // left click
            if (event.bstate & BUTTON1_CLICKED) {
                Food food;
                food.position[0] = x;
                food.position[1] = y;
                foods->push_back(&food);
            }
        }
        view->render(chickens,foods);
    }

        
        
    }
