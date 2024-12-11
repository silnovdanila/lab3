#pragma once
#include "Dish.h"
class HotDish :
    public Dish
{
private:
    int weight;
public:
    HotDish(int price, std::string s, int weight) : Dish(price, s) {
        this->weight = weight;
    }
    HotDish() = default;
    void getDiscription() {
        std::cout << this->name << "  " << this->weight << " gr" << "  " << this->price;
    }
};

