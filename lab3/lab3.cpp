#include "DiscountCard.h"
#include "Dish.h"
#include "Menu.h"
#include <iostream>

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
}

