#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
		std::cin.ignore();
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
	void payWithCard() {
		int sum;
		scanf("%d", &sum);
		std::cout << "\nThe payment was successful";
	}
	void payClient() {
		int sum;
		double* discount = new double;
		this->card.getDiscount(discount);
		this->currentOrder.orderSum(sum);
		std::cout << "\nThe price of order is " << sum * (1 - *discount)  << " rub, your discount is "<< *discount * 100 << "%";
		std::cout << "\nEnter the card details for the payment: ";
		this->payWithCard();
	}
	void addHistory() {
		this->card.setDiscount(this->card.getNewDiscount(this->card.getDiscount()));
		this->card.addTOhistoryOForders(this->currentOrder);
	}
};

