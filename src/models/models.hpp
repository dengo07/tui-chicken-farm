#ifndef MODEL_HPP
#define MODEL_HPP

#include<string>
#include<vector>

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

};



//Chicken model
struct Chicken
{
    std::string art = "C";
    std::string name;
    ChickenState state;
    std::vector<Food*>* foods;
    int* position = new int[2];//position (x,y)
    void setState(ChickenState);
    Food* closestFood();
    void updatePosition();
};



#endif