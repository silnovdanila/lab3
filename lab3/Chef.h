#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include "Order.h"
#include "iostream"
class Chef :
    public Employee
{
private:
    std::string name;
    Order currentOrder;
public:
    Chef(std::string name, int salary, std::string job) : Employee(salary, job){
        this->name = name;
        this->currentOrder;
    }
    Chef() = default;
    std::string getName() {
        return this->name;
    }
    void setOrder(Order order) {
        this->currentOrder = order;
    }
};

