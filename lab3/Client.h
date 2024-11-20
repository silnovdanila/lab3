#pragma once
#include "Order.h"
#include "DiscountCard.h"
#include "iostream"
class Client
{
private:
	std::string name;
	DiscountCard card;
	Order currentOrder;
public:
	Client(int id, std::string name) {
		this->card = DiscountCard(id);
		this->name = name;
	}
};

