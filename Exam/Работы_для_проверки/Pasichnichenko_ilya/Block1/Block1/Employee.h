#pragma once
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Employee
{
protected:
	string position;
	string BankCardAccount;
	double salary;

	Employee() {};
	Employee(const Employee& obj) {}
public:
	
	void setPosition(string position){this->position = position;}
	void setBankCardAccount(string BankCardAccount){this->BankCardAccount = BankCardAccount;}
	void setSalary(double salary){this->salary = salary;}

	string getPosition(){return position;}
	string getBankCardAccount(){return BankCardAccount;}
	double getSalary(){return salary;}

	Employee(string position, string BankCardAccount, double salary)
	{
		this->position = position;
		this->BankCardAccount = BankCardAccount;
		this->salary = salary;
	}

};