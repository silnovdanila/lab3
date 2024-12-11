#pragma once
#include "Dish.h"
class Dessert :
    public Dish
{
private:
    int weight;
    int isSugar;
public:
    Dessert(int price, std::string s, int weight, int isSugar) : Dish(price, s) {
        this->weight = weight;
        this->isSugar = isSugar;
    }
    Dessert() = default;
    void getDiscription() {
        if (isSugar == 0) {
            std::cout << this->name << " with no sugar  " << this->weight << " gr  " << this->price << " rub";
        }
        else {
            std::cout << this->name << "  " << this->price << "  " << this->weight << " gr";
        }
    }
};

