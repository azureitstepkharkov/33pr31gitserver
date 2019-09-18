#pragma once
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Employee
{
protected:
	string position;
	string BankAccount;
	double salary;

	Employee() {};
	Employee(const Employee& obj) {}
public:

	void setPosition(string position) { this->position = position; }
	void setBankAccount(string BankAccount) { this->BankAccount = BankAccount; }
	void setSalary(double salary) { this->salary = salary; }

	string getPosition() { return position; }
	string getBankAccount() { return BankAccount; }
	double getSalary() { return salary; }

	Employee(string position, string BankAccount, double salary)
	{
		this->position = position;
		this->BankAccount = BankAccount;
		this->salary = salary;
	}

};
