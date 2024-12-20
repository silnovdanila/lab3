#define _CRT_SECURE_NO_WARNINGS
#include "OrderFunc.h"

void getOrder(std::string clientName, std::string waiterName, std::string povarName, Menu menu, int order[]) {
	int num;
	std::cout << "\nHello, " << clientName;
	std::cout << "\nYour waiter - " << waiterName;
	std::cout << "\nYour chef - " << povarName;
	std::cout << "\nHere is the menu";
	menu.menuOut();
	std::cout << "\nHow many dishes you want to order. Enter number < 20 - ";
	std::cin >> num;
	std::cout << "To place an order, enter the number of items you want to order - ";
	int i = 0;
	for (i; i < num; i++) {
		scanf("%d", &order[i]);
	}
	order[i] = 0;
}
void makeOrder(Client* client, Waiter* waiter, Chef* povar, Menu menu, int sp[]) {
	Dish* dishes = new Dish[20];
	int dish = 0;
	for (int i = 0; sp[i] != 0; i++) {
		if (sp[i] <= menu.getHotDishesAmount()) {
			dishes[dish] = menu.getHotDish(sp[i] - 1);
		}
		else if (sp[i] <= menu.getHotDishesAmount() + menu.getdessertAmount()) {
			dishes[dish] = menu.getdessert(sp[i] - menu.getHotDishesAmount() - 1);
		}
		else {
			dishes[dish] = menu.getdrink(sp[i] - menu.getHotDishesAmount() - menu.getdessertAmount() - 1);
		}
		dish += 1;
	}
	Order* newOrder = new Order;
	int i = 0;
	while (i != dish) {
		newOrder+=dishes[i];
		i++;
	}
	client->setOrder(*newOrder);
	waiter->setOrder(*newOrder);
	povar->setOrder(*newOrder);
}