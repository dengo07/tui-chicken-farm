#include "models.hpp"


void Chicken::setState(ChickenState newState){
    state = newState;
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
        /* code */
        break;
    
    default:
        break;
    }
}