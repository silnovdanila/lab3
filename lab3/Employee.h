#pragma once
#include "iostream"
class Employee
{
private:
	int salary;
	std::string job;
public:
	Employee(int salary, std::string job) {
		this->salary = salary;
		this->job = job;
	}
};

