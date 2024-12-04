#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Dish.h"
#include "iostream"
class Order
{
private:
	Dish* order = new Dish[20];
	int dishes;
public:
	Order() {
		this->dishes = 0;
	}
	//Order() = default;
	void addDish(Dish dish) {
		this->order[this->dishes++] = dish;
	}
	int orderSum() {
		int sum = 0;
		printf("\nYour order: ");
		for (int i = 0; i < dishes; i++) {
			if (i != dishes - 1) { std::cout << this->order[i].getName() << ", "; }
			else { std::cout << this->order[i].getName(); }
			sum += this->order[i].getPrice();
		}
		return sum;
	}
};

