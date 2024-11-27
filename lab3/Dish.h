#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
class Dish
{
	private:
		int price;
		std::string name;
	public:
		Dish(int price, std::string s) {
			this->price = price;
			this->name = s;
		}
		Dish() = default;
		int getPrice() const {
			return this->price;
		}
		std::string getName() const {
			return this->name;
		}
};

