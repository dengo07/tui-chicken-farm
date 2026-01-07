#include "models.hpp"


void Chicken::setState(ChickenState newState){
    state = newState;
}


Food* Chicken::closestFood(){

}

void Chicken::updatePosition(){
    switch (state)
    {
    case ChickenState::STANDING:
        //No update in position
        break;
    case ChickenState::WALKING:
        /* code */
        break;
    case ChickenState::TOFOOD:
        if(!foods->empty()){
            //aligning x axis;
            if(foods->at(0)->position[0]>position[0]){
                position[0]++;
            }
            else{
                position[0]--;
            }
            
            //aligning y axis
            if(foods->at(0)->position[1]>position[1]){
                position[1]++; 
            }
            else{
                position[1]--;
            }
            //check collision
            int diffX = abs(foods->at(0)->position[0] - position[0]);
            int diffY = abs(foods->at(0)->position[1] - position[1]);

            if (diffX <= 1 && diffY <= 1) {
            
                delete foods->at(0); 
                foods->erase(foods->begin());
            }
            
        }   
        else{
            //setting back to walking state
            setState(ChickenState::WALKING);
        }
        break;
    
    default:
        break;
    }
}