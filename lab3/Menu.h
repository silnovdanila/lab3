#pragma once
#include "Dish.h"
#include <iostream>
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
	void addHotDish(Dish dish) {
		hotDishes[hotDishAmount++] = dish;
	}
	void addDessert(Dish dish) {
		desserts[dessertAmount++] = dish;
	}
	void addDrink(Dish dish) {
		drinks[drinkAmount++] = dish;
	}
	void menuOut() {
		if (this->hotDishAmount != 0) {
			std::cout << "\n\n\tMENU\nHot Dishes:\n";
			for (int i = 0; i < this->hotDishAmount; i++) {
				std::cout << i + 1 << " - " << this->hotDishes[i].getName() << "  " << this->hotDishes[i].getPrice() << '\n';
			}
		}
		if (this->dessertAmount != 0) {
			std::cout << "\nDesserts:\n";
			for (int i = 0; i < this->dessertAmount; i++) {
				std::cout << i + 1 + this->hotDishAmount << " - " << this->desserts[i].getName() << "  " << this->desserts[i].getPrice() << '\n';
			}
		}
		if (this->drinkAmount != 0) {
			std::cout << "\nDrinks:\n";
			for (int i = 0; i < this->drinkAmount; i++) {
				std::cout << i + 1 + this->hotDishAmount + this->dessertAmount << " - " << this->desserts[i].getName() << "  " << this->desserts[i].getPrice() << '\n';
			}
		}
	}
};

