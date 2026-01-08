#include "models.hpp"

void Chicken::setState(ChickenState newState){
    state = newState;
}



std::pair<Food*, int> Chicken::closestFood() {
    std::pair<Food*, int> bestTarget = {nullptr, -1}; 
    std::pair<Food*, int> backupTarget = {nullptr, -1}; 

    if (foods == nullptr || foods->empty()) {
        return bestTarget;
    }

    double minFreeDist = 1e18; 
    double minAnyDist = 1e18;  

    for (int i = 0; i < foods->size(); i++) {
        Food* currentFood = foods->at(i);
        

        double dx = currentFood->position[0] - position[0];
        double dy = currentFood->position[1] - position[1];
        double dist = sqrt(dx * dx + dy * dy);

        if (!currentFood->isFull) {
            if (dist < minFreeDist) {
                minFreeDist = dist;
                bestTarget = {currentFood, i};
            }
        }

        else {
            if (dist < minAnyDist) {
                minAnyDist = dist;
                backupTarget = {currentFood, i};
            }
        }
    }

  
    if (bestTarget.first != nullptr) {
        return bestTarget;
    }
    
    return backupTarget;
}

void Chicken::updatePosition(){
 
    if(targetedFood.first == nullptr){
        targetedFood = closestFood();
    }
    
    switch (state)
    {
    case ChickenState::STANDING:
        //No update in position
        break;
    case ChickenState::WALKING:
        /* code */
        break;
    case ChickenState::TOFOOD:

        if (targetedFood.first != nullptr) {
        bool targetStillExists = false;
        for (auto f : *foods) {
            if (f == targetedFood.first) {
                targetStillExists = true;
                break;
            }
        }
            
 
        if (!targetStillExists) {
            targetedFood = {nullptr, -1};
            state = ChickenState::WALKING; 
            return; 
            }
        }
        if(!foods->empty() && targetedFood.first != nullptr){
            //aligning x axis;
            if(targetedFood.first->position[0]>position[0]){
                position[0]++;
            }
            else{
                position[0]--;
            }
            
            //aligning y axis
            if(targetedFood.first->position[1]>position[1]){
                position[1]++; 
            }
            else{
                position[1]--;
            }
            //check collision
            int diffX = abs(targetedFood.first->position[0] - position[0]);
            int diffY = abs(targetedFood.first->position[1] - position[1]);

            if (diffX <= 1 && diffY <= 1) {
                if(targetedFood.first != nullptr){
                    bool found = false;
                    for(auto it = foods->begin(); it != foods->end(); ++it) {
                        if (*it == targetedFood.first) {
                            delete *it;       
                            foods->erase(it); 
                            found = true;
                            break; 
                        }
                    }
                    targetedFood = {nullptr, -1};
                }
                
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