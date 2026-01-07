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

        //Mouse control to be able to put food on the screen
        if (getmouse(&event) == OK) {
            int x = event.x;
            int y = event.y;

            // left click
            if (event.bstate & BUTTON1_CLICKED) {
                Food* food = new Food();
                food->position[0] = x;
                food->position[1] = y;
                foods->push_back(food);
            }
        }

        // 'a' key to add chickensss
        if(ch == 'a'){
            static int x = 1; static int y =1;
            Chicken* chick = new Chicken();
            chick->foods = foods;
            chick->position[0] = ++x;
            chick->position[1] = ++y;
            chickens->push_back(chick);
        }

        //Setting chickens state to TOFOOD if there is food on the screen
        if(!foods->empty() && !chickens->empty() ){
            for(int i = 0; i<chickens->size();i++){
                if(chickens->at(i)){
                    chickens->at(i)->setState(ChickenState::TOFOOD);
                }
                
            }
        }
        else{
            for(int i = 0; i<chickens->size();i++){
                if(chickens->at(i)){
                    chickens->at(i)->setState(ChickenState::STANDING);
                }
               
        }


        
        }
    view->render(chickens,foods);
    }

} 
        
        
