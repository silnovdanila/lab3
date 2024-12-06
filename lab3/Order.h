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
	Order(const Order& order) {
		this->dishes = order.dishes;
		for (int i = 0; i < this->dishes; i++) {
			this->order[i] = order.order[i];
		}
	}
	void addDish(Dish dish) {
		this->order[this->dishes++] = dish;
	}
	void orderSum(int& sum) {
		sum = 0;
		printf("\nYour order: ");
		for (int i = 0; i < dishes; i++) {
			if (i != dishes - 1) { std::cout << this->order[i].getName() + ", "; }
			else { std::cout << this->order[i].getName(); }
			sum += this->order[i].getPrice();
		}
	}
	friend Order operator+(Order order, Dish dish) {
		order.order[order.dishes++] = dish;
		return order;
	}
	friend Order* operator+(Order* order, Dish dish) {
		order->order[order->dishes++] = dish;
		return order;
	}
	friend Order operator+=(Order order, Dish dish) {
		order.order[order.dishes++] = dish;
		return order;
	}
	friend Order* operator+=(Order* order, Dish dish) {
		order->order[order->dishes++] = dish;
		return order;
	}
	Dish operator[](int index) {
		return this->order[index];
	}
};