#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Dish.h"
#include "HotDish.h"
#include "Dessert.h"
#include "Drink.h"
#include <iostream>
class Menu
{
private:
	int hotDishAmount;
	int dessertAmount;
	int drinkAmount;
	HotDish* hotDishes = new HotDish[20];
	Dessert* desserts = new Dessert[20];
	Drink* drinks = new Drink[20];
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
	void addHotDish(HotDish dish) {
		hotDishes[hotDishAmount++] = dish;
	}
	int deleteHotDish(int index) {
		if (index < 0 || index > this->hotDishAmount) {
			return -1;
		}
		else {
			for (int i = index; i < this->hotDishAmount - 1; i++) {
				this->hotDishes[i] = this->hotDishes[i + 1];
			}
			this->hotDishAmount -= 1;
			return 0;
		}
	}
	int deleteDessert(int index) {
		if (index < 0 || index > this->dessertAmount) {
			return -1;
		}
		else {
			for (int i = index; i < this->dessertAmount - 1; i++) {
				this->desserts[i] = this->desserts[i + 1];
			}
			this->dessertAmount -= 1;
			return 0;
		}
	}
	int deleteDrink(int index) {
		if (index < 0 || index > this->drinkAmount) {
			return -1;
		}
		else {
			for (int i = index; i < this->drinkAmount - 1; i++) {
				this->drinks[i] = this->drinks[i + 1];
			}
			this->drinkAmount -= 1;
			return 0;
		}
	}
	void addDessert(Dessert dish) {
		desserts[dessertAmount++] = dish;
	}
	void addDrink(Drink dish) {
		drinks[drinkAmount++] = dish;
	}
	void menuOut() {
		if (this->hotDishAmount != 0) {
			std::cout << "\n\n\tMENU\nHot Dishes:\n";
			for (int i = 0; i < this->hotDishAmount; i++) {
				std::cout << i + 1 << " - ";
				this->hotDishes[i].getDiscription();
				std::cout << '\n';
			}
		}
		if (this->dessertAmount != 0) {
			std::cout << "\nDesserts:\n";
			for (int i = 0; i < this->dessertAmount; i++) {
				std::cout << i + 1 + this->hotDishAmount << " - ";
				this->desserts[i].getDiscription();
				std::cout << '\n';
			}
		}
		if (this->drinkAmount != 0) {
			std::cout << "\nDrinks:\n";
			for (int i = 0; i < this->drinkAmount; i++) {
				std::cout << i + 1 + this->hotDishAmount + this->dessertAmount << " - ";
				this->drinks[i].getDiscription();
				std::cout << '\n';
			}
		}
	}
};

