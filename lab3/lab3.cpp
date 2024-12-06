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
    Dish* hotdish1 = new Dish(1200, "Mashed potato");
    menu->addHotDish(*hotdish1);
    Dish* hotdish2 = new Dish(1100, "Sup");
    menu->addHotDish(*hotdish2);
    Dish* dessert1 = new Dish(700, "Cake");
    menu->addDessert(*dessert1);
    Dish* drink1 = new Dish(120, "Tea");
    menu->addDrink(*drink1);
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

