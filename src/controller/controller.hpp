#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include<vector>
#include "../view/view.hpp"
#include "../models/models.hpp"


struct Controller
{
    std::vector<Chicken*>* chickens;
    std::vector<Food*>* foods;
    View* view;

    Controller(View*,std::vector<Chicken*>* ,std::vector<Food*>* );

    void run();
};


#endif