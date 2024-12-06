#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Order.h"
#include <iostream>

class DiscountCard
{
private:
	double discount;
	Order* historyOForders = new Order[20];
	int orders;
	static int id;
public:
	DiscountCard() {
		this->id++;
		this->discount = 0;
		this->orders = 0;
	}
	DiscountCard(const DiscountCard& card) {
		this->discount = card.discount;
		this->id = id++;
		this->orders = card.orders;
		this->historyOForders = new Order[20];
		for (int i = 0; i < this->orders; i++) {
			this->historyOForders = &card.historyOForders[i];
		}
	}
	void newID() {
		this->id++;
	}
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
	friend DiscountCard operator+(DiscountCard card, Order order) {
		card.historyOForders[card.orders] = order;
		card.orders += 1;
		return card;
	}
	friend DiscountCard operator+=(DiscountCard card, Order order) {
		card.historyOForders[card.orders] = order;
		card.orders += 1;
		return card;
	}
	friend DiscountCard* operator+(DiscountCard* card, Order order) {
		card->historyOForders[card->orders] = order;
		card->orders += 1;
		return card;
	}
	friend DiscountCard* operator+=(DiscountCard* card, Order order) {
		card->historyOForders[card->orders] = order;
		card->orders += 1;
		return card;
	}
};

