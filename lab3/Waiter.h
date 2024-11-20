#pragma once
#include "Employee.h"
#include "Order.h"
#include "iostream"
class Waiter :
    public Employee
{
private:
    std::string name;
    Order currentOrder;
public:
    Waiter(std::string name, int salary, std::string job) : Employee(salary, job) {
        this->name = name;
        this->currentOrder;
    }
};

