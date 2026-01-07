#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include<vector>
#include<random>
#include "../view/view.hpp"
#include "../models/models.hpp"


struct Controller
{
    std::vector<Chicken*>* chickens;
    std::vector<Food*>* foods;
    int gameSpeed = 60;
    View* view;

    Controller(View*,std::vector<Chicken*>* ,std::vector<Food*>* );

    void randomFeeding();

    void run();
};


#endif