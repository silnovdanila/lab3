#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
class Employee abstract
{
protected:
	int salary;
	std::string job;
	std::string name;
public:
	Employee(int salary, std::string job, std::string name) {
		this->salary = salary;
		this->job = job;
		this->name = name;
	}
	Employee(const Employee& emp) {
		this->job = emp.job;
		this->name = emp.name;
		this->salary = emp.salary;
	}
	Employee() = default;
	std::string getName() {
		return this->name;
	}
};

