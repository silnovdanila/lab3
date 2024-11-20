#pragma once
#include "Dish.h"
class Menu
{
private:
	int hotDishAmount;
	int dessertAmount;
	int drinkAmount;
	Dish* hotDishes = new Dish[20];
	Dish* desserts = new Dish[20];
	Dish* drinks = new Dish[20];
public:
	Menu() {
		this->dessertAmount = 0;
		this->hotDishAmount = 0;
		this->drinkAmount = 0;
	}
	Menu() = default;
};

