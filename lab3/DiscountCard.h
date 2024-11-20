#pragma once
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
};

