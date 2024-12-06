#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
    Waiter(std::string name, int salary, std::string job) : Employee(salary, job, name) {
        this->name = name;
        this->currentOrder;
    }

    Waiter(const Waiter& waiter) {
        this->job = waiter.job;
        this->name = waiter.name;
        this->salary = waiter.salary;
        this->currentOrder = waiter.currentOrder;
    }
    Waiter() = default;
    void setOrder(Order order) {
        this->currentOrder = order;
    }
};

