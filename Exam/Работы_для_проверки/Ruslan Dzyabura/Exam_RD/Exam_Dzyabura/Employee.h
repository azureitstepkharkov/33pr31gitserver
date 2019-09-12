#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include"HumanEntity.h"
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Employee:public Person
{
protected:
	string position;
	string bank_account;
	double salary;
	 Employee() { cout << "call Employee()" << endl; };
	 Employee(const Employee& obj) { cout << "const Employee& obj" << endl; };
	~Employee() {};
public:
	Employee(string Pos, string Bank_acc, double sal) {
		this->position = Pos;
		this->bank_account = Bank_acc;
		this->salary = sal;
	}
	void setPosition(string pos) { this->position = pos; }
	void setBank(string bank) { this->bank_account = bank; }
	void setSalary(double sal) { this->salary = sal; }
	string getPosition() { return position; }
	string getBank() { return bank_account; }
	double getSalary() { return salary; }
	friend ostream& operator << (ostream& out_data, Employee& e)
	{
		out_data << "Position is " << e.position << endl;
		out_data << "Salary is " << e.salary << endl;
		out_data << "Ban account is " << e.bank_account << endl;
	

		return out_data;
	};
};

