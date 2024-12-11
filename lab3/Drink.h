#pragma once
#include "Dish.h"
class Drink :
    public Dish
{
private:
    int ml;
    int alcohol;
public:
    Drink(int price, std::string s, int ml, int alcohol) : Dish(price, s) {
        this->ml = ml;
        this->alcohol = alcohol;
    }
    Drink() = default;
    void getDiscription() {
        if (alcohol == 0) {
            std::cout << this->name << "  " << this->ml << " ml" << "  " << this->price;
        }
        else {
            std::cout << this->name << "  " << this->alcohol << "% alcohol  " << this->ml << " ml  " << this->price;
        }
    }
};

