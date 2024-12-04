#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "Dish.h"
#include "Menu.h"
#include "Waiter.h"
#include "Chef.h"
#include "Client.h"
#include "Order.h"

void getOrder(std::string clientName, std::string waiterName, std::string povarName, Menu menu, int order[]);
void makeOrder(Client* client, Waiter* waiter, Chef* povar, Menu menu, int sp[]);