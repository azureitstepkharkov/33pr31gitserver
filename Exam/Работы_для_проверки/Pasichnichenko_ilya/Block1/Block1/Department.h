#pragma once
#include"Employee.h"
#include<string>
#include<iostream>	
#include <fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<list>
using namespace std;
class Department : public Employee
{
private:
	string Name;
	list<Employee*> emploeeList;
	string departmentDirector;
public:

	friend ostream& operator<< (ostream& os, Department& data)
	{
		os << "Name = " << data.Name << " departmentDirector = " << data.departmentDirector
			<< " emploeeList = " << data.printEmploeeList() << endl;
		return os;
	}

	void setName(string Name)
	{
		this->Name = Name;
	}

	void pushBackEmployeeList(string position, string BankCardAccount, double salary)
	{
		Employee* m = new Employee(position, BankCardAccount, salary);
		emploeeList.push_back(m);
	}

	void printEmploeeList()
	{
		for_each(emploeeList.begin(), emploeeList.end(), printEmployee);
	}

	Department() {};
	~Department() {};
};

