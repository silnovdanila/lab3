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
	Client(std::string name) {
		this->card = DiscountCard();
		this->name = name;
	}
	Client(const Client& client) {
		this->name = client.name;
		this->currentOrder = client.currentOrder;
		this->card = client.card;
		this->card.newID();
	}
	static Client getNewClient() {
		std::cout << "\nWelcome to the cafe\nPlease, enter your name - ";
		char s[80];
		std::cin.ignore();
		std::cin.getline(s, 80);
		std::unique_ptr<Client> client(new Client(s));
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
		label:
		std::cout << "\nEnter the PIN of yout card for the payment: ";
		try {
			std::cin >> sum;
		}
		catch(std::exception &e){
			goto label;
		}
		if (sum < 1000 || sum > 9999) {
			throw std::range_error("PIN is incorrect");
		}
		std::cout << "\nThe payment was successful";
	}
	void payClient() {
		int sum;
		std::shared_ptr<double> discount(new double);
		this->card.getDiscount(discount);
		this->currentOrder.orderSum(sum);
		std::cout << "\nThe price of order is " << sum * (1 - *discount)  << " rub, your discount is "<< *discount * 100 << "%";
		try {
			this->payWithCard();
		}
		catch (std::range_error) {
			std::cout << "\nPIN is incorrect. Your order is canceled.\n";
		}
	}
	void addHistory() {
		this->card.setDiscount(this->card.getNewDiscount(this->card.getDiscount()));
		this->card.addTOhistoryOForders(this->currentOrder);
	}
};

