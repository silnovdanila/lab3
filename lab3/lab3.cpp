#define _CRT_SECURE_NO_WARNINGS
#include "DiscountCard.h"
#include "Dish.h"
#include "Menu.h"
#include "Order.h"
#include "Chef.h"
#include "Waiter.h"
#include "Client.h"
#include "OrderFunc.h"
#include <iostream>
int DiscountCard::id = 0;

int main()
{
    Menu* menu = new Menu;
    HotDish* hotdish1 = new HotDish(1200, "Mashed potato", 300);
    menu->addHotDish(*hotdish1);
    HotDish* hotdish2 = new HotDish(1100, "Sup", 350);
    menu->addHotDish(*hotdish2);
    Dessert* dessert1 = new Dessert(700, "Cake", 200, 0);
    menu->addDessert(*dessert1);
    Drink* drink1 = new Drink(120, "Tea", 200, 0);
    menu->addDrink(*drink1);
    Drink* drink2 = new Drink(500, "Margarita", 300, 10);
    menu->addDrink(*drink2);
    menu->menuOut();
    Chef povar1 = *new Chef("Vasiliy", 60000, "Chef");
    Chef povar2 = *new Chef("Gregory", 45000, "Povar");
    Chef povar3 = *new Chef("Egor", 45000, "Povar");
    Waiter* waiter1 = new Waiter("Anna", 45000, "Waiter");
    Waiter* waiter2 = new Waiter("Anna", 45000, "Waiter");

    Chef* povara = new Chef[3] {povar1, povar2, povar3};
    Waiter *waiters[2] = {waiter1, waiter2};
    int order[20];
    Client client1 = Client::getNewClient();
    getOrder(client1.getName(), waiters[0]->getName(), povara[0].getName(), *menu, order);
    makeOrder(&client1, waiters[1], &povara[1], *menu, order);
    client1.payClient();
    client1.addHistory();

    Client client2 = Client::getNewClient();
    getOrder(client2.getName(), waiters[1]->getName(), povara[1].getName(), *menu, order);
    makeOrder(&client2, waiters[1], &povara[2], *menu, order);
    client2.payClient();
    client2.addHistory();

    getOrder(client1.getName(), waiters[1]->getName(), povara[2].getName(), *menu, order);
    makeOrder(&client1, waiters[1], &povara[2], *menu, order);
    client1.payClient();
    client1.addHistory();
}

