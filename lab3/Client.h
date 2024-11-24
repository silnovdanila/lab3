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
	static Client getNewClient(int id) {
		std::cout << "\nWelcome to the cafe\nPlease, enter your name - ";
		char s[80];
		std::cin.getline(s, 80);
		Client *client = new Client(id, s);
		return *client;
	}
	std::string getName() {
		return this->name;
	}
	void setOrder(Order order) {
		this->currentOrder = order;
	}
};

