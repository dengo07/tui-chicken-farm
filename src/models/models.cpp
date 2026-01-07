#include "models.hpp"

void Chicken::setState(ChickenState newState){
    state = newState;
}


std::pair<Food*, int> Chicken::closestFood() {
   
    std::pair<Food*, int> ret = {nullptr, -1};

    if (foods == nullptr || foods->empty()) {
        return ret;
    }

    double minDistance = 1e18; 

    for (int i = 0; i < foods->size(); i++) {
        int dx = foods->at(i)->position[0] - position[0];
        int dy = foods->at(i)->position[1] - position[1];
        
        double currDistance = sqrt(dx * dx + dy * dy); 

        if (currDistance < minDistance) {
            minDistance = currDistance;
            ret.first = foods->at(i);
            ret.second = i;
        }
    }
    return ret;
}

void Chicken::updatePosition(){
    std::pair<Food*,int> food;
 
    food = closestFood();
    
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
            if(food.first->position[0]>position[0]){
                position[0]++;
            }
            else{
                position[0]--;
            }
            
            //aligning y axis
            if(food.first->position[1]>position[1]){
                position[1]++; 
            }
            else{
                position[1]--;
            }
            //check collision
            int diffX = abs(food.first->position[0] - position[0]);
            int diffY = abs(food.first->position[1] - position[1]);

            if (diffX <= 1 && diffY <= 1) {
            
                delete foods->at(food.second); 
                foods->erase(foods->begin()+food.second);
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