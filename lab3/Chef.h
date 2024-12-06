#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include "Order.h"
#include "iostream"
class Chef :
    public Employee
{
private:
    Order currentOrder;
public:
    Chef(std::string name, int salary, std::string job) : Employee(salary, job, name){
        this->currentOrder;
    }
    Chef(const Chef& chef) {
        this->job = chef.job;
        this->name = chef.name;
        this->salary = chef.salary;
        this->currentOrder = chef.currentOrder;
    }
    Chef() = default;
    void setOrder(Order order) {
        this->currentOrder = order;
    }
};

