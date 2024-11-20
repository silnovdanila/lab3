#pragma once
#include "iostream"
#include "Dish.h"
class Order
{
private:
	Dish* order = new Dish[20];
public:
	Order() = default;
};

