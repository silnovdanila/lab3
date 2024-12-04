#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
class Employee
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
	std::string getName() {
		return this->name;
	}
};

