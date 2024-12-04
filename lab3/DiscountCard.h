#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Order.h"
class DiscountCard
{
private:
	int id;
	double discount;
	Order* historyOForders = new Order[20];
	int orders;
public:
	DiscountCard(int id) {
		this->id = id;
		this->discount = 0;
		this->orders = 0;
	}
	DiscountCard() = default;
	void getDiscount(double *discount) const {
		*discount = this->discount;
	}
	double getDiscount() {
		return this->discount;
	}
	void setDiscount(double b) {
		this->discount = b;
	}
	static double getNewDiscount(double discount) {
		if (discount >= 0.089) {
			return 0.1;
		}
		return discount += 0.01;
	}
	void addTOhistoryOForders(Order newOrder) {
		this->historyOForders[this->orders++] = newOrder;
	}
};

