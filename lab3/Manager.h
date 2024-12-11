#pragma once
#include "Employee.h"
class Manager :
    public Employee
{
private:
public:
    Manager(std::string name, int salary, std::string job) : Employee(salary, job, name) {
    }
    Manager(const Manager& man) {
        this->job = man.job;
        this->name = man.name;
        this->salary = man.salary;
    }
    Manager() = default;
};
