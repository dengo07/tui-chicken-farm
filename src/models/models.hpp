#ifndef MODEL_HPP
#define MODEL_HPP

#include<string>
#include<vector>
#include<cmath>

//states for chicken behaviours
enum class ChickenState{
    STANDING,
    WALKING,
    TOFOOD
};

//Food model
struct Food{
    std::string art = ":::";
    int* position = new int[2];//position (x,y)
    bool isFull = false;

};



//Chicken model
struct Chicken
{
    std::string art = "C";
    std::string name;
    ChickenState state;
    std::vector<Food*>* foods;
    std::pair<Food*,int> targetedFood;
    int* position = new int[2];//position (x,y)
    void setState(ChickenState);
    std::pair<Food*,int> closestFood();
    void updatePosition();
};



#endif