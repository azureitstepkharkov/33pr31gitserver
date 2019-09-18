#pragma once
#include"Employee.h"
#include"MyList.h"

#include<string>
#include<iostream>	
#include <fstream>
using namespace std;
class Department : public Employee
{
private:
	string DepName;
	string DepDirector;

	Department() {};
public:
	void setDepName(string DepName) { this->DepName = DepName; }
	void setDepDirector(string DepDirector) { this->DepDirector = DepDirector; }

	string getDepName() { return DepName; }
	string getDepDirector() { return DepDirector; }

	Department(string DepName, string DepDirector, string position, string BankAccount, double salary)
		:Employee(position, BankAccount, salary)
	{
		this->DepName = DepName;
		this->DepDirector = DepDirector;
	}

	friend ostream&  operator<< (ostream& out_data, Department& data)
	{
		out_data <<
			"Department name = " << data.getDepName() << endl <<
			"Department director = " << data.getDepDirector() << endl <<
			"Position = " << data.getPosition() << endl <<
			"Bank card account = " << data.getBankAccount() << endl <<
			"Salary = " << data.getSalary() << endl;
		return out_data;
	};

	void Print()
	{
		cout << "Department name = " << getDepName() << endl <<
			"Department director = " << getDepDirector() << endl <<
			"Position = " << getPosition() << endl <<
			"Bank card account = " << getBankAccount() << endl <<
			"Salary = " << getSalary() << endl;
	}

};