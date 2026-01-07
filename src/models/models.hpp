#ifndef MODEL_HPP
#define MODEL_HPP
#include<string>

enum class ChickenState{
    WALKING,
    TOFOOD
};


struct Chicken
{
    std::string art = "🐔";
    std::string name;
};

struct Food{
    std::string art = "🍞";

};





#endif