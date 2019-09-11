#pragma once
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Employee : public Person
{
private:
	string position;
	string BankCardAccount;
	double salary;
public:
	Employee() {};
	~Employee() {};

	friend ostream& operator<< (ostream& os, Employee& data)
	{
		os << "BankCardAccount = " << data.BankCardAccount << " position = " << data.position
			<< " salary = " << data.salary << endl;
		return os;
	}

	void setPosition(string position)
	{
		this->position = position;
	}

	void setBankCardAccount(string BankCardAccount)
	{
		this->BankCardAccount = BankCardAccount;
	}

	void setSalary(double salary)
	{
		this->salary = salary;
	}

	string getPosition()
	{
		return position;
	}

	string getBankCardAccount()
	{
		return BankCardAccount;
	}

	double getSalary()
	{
		return salary;
	}

	Employee(string position, string BankCardAccount, double salary)
	{
		this->position = position;
		this->BankCardAccount = BankCardAccount;
		this->salary = salary;
	}

	void printEmployee()
	{
		cout << "position = " << position << " ";
		cout << "BankCardAccount = " << BankCardAccount << " ";
		cout << "salary = " << salary << " ";

	}

};


