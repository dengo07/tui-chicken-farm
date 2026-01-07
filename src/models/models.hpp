#ifndef MODEL_HPP
#define MODEL_HPP

#include<string>


//states for chicken behaviours
enum class ChickenState{
    STANDING,
    WALKING,
    TOFOOD
};

//Chicken model
struct Chicken
{
    std::string art = "C";
    std::string name;
    ChickenState state;
    int* position = new int[2];//position (x,y)
    void setState(ChickenState);
    void updatePosition();
};


//Food model
struct Food{
    std::string art = ":::";
    int* position = new int[2];//position (x,y)

};





#endif