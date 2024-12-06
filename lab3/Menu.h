#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	Menu(const Menu& menu) {
		this->dessertAmount = menu.dessertAmount;
		this->hotDishAmount = menu.hotDishAmount;
		this->drinkAmount = menu.drinkAmount;
		for (int i = 0; i < this->dessertAmount; i++) {
			this->desserts[i] = menu.desserts[i];
		}
		for (int i = 0; i < this->hotDishAmount; i++) {
			this->hotDishes[i] = menu.hotDishes[i];
		}
		for (int i = 0; i < this->drinkAmount; i++) {
			this->drinks[i] = menu.drinks[i];
		}
	}
	Dish getHotDish(int a) {
		return this->hotDishes[a];
	}
	Dish getdessert(int a) {
		return this->desserts[a];
	}
	Dish getdrink(int a) {
		return this->drinks[a];
	}
	int getdessertAmount() {
		return this->dessertAmount;
	}
	int getdrinkAmount() {
		return this->drinkAmount;
	}
	int getHotDishesAmount() {
		return this->hotDishAmount;
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

