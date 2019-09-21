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
	string DepartmentName;
	string DepartmentDirector;

	Department() {};
public:
	void setDepartmentName(string DepartmentName) { this->DepartmentName = DepartmentName; }
	void setDepartmentDirector(string DepartmentDirector) { this->DepartmentDirector = DepartmentDirector; }

	string getDepartmentName() { return DepartmentName; }
	string getDepartmentDirector() { return DepartmentDirector; }

	Department(string DepartmentName, string DepartmentDirector,string position, string BankCardAccount, double salary)
		:Employee(position, BankCardAccount, salary)
	{
		this->DepartmentName = DepartmentName;
		this->DepartmentDirector = DepartmentDirector;
	}

	friend ostream&  operator<< (ostream& out_data, Department& data)
	{
		out_data <<
			"Department name = " << data.getDepartmentName() << endl <<
			"Department director = " << data.getDepartmentDirector() << endl <<
			"Position = " << data.getPosition() << endl <<
			"Bank card account = " << data.getBankCardAccount() << endl <<
			"Salary = " << data.getSalary() << endl;
		return out_data;
	};

	void Print()
	{
		cout<<"Department name = " << getDepartmentName() << endl <<
			"Department director = " << getDepartmentDirector() << endl <<
			"Position = " << getPosition() << endl <<
			"Bank card account = " << getBankCardAccount() << endl <<
			"Salary = " << getSalary() << endl;
	}

};