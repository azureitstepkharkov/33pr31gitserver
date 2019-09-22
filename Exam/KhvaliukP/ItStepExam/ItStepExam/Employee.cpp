#include "pch.h"
#include "Employee.h"


Employee::Employee()
{
}

Employee::Employee(char * employee_, char * card_account_, int salary_)
{
	employee = new char[strlen(employee_) + 1];
	strcpy_s(employee, strlen(employee_) + 1, employee_);
	delete[] employee_;

	card_account = new char[strlen(card_account_) + 1];
	strcpy_s(card_account, strlen(card_account_) + 1, card_account_);
	delete[] card_account_;

	salary = salary_;
}

void Employee::Set_Employee(char * employee_)
{
	employee = new char[strlen(employee_) + 1];
	strcpy_s(employee, strlen(employee_) + 1, employee_);
	delete[] employee_;
}

void Employee::Set_CardAccount(char * card_account_)
{
	card_account = new char[strlen(card_account_) + 1];
	strcpy_s(card_account, strlen(card_account_) + 1, card_account_);
	delete[] card_account_;
}

void Employee::Set_Salary(int salary_)
{
	salary = salary_;
}

char * Employee::Get_Employee()
{
	return employee;
}

char * Employee::Get_CardAccount()
{
	return card_account;
}

int Employee::Get_Salary()
{
	return salary;
}


Employee::~Employee()
{
	delete[] employee;
	delete[] card_account;
}

ostream & operator<<(ostream & output, Employee & empl)
{
	output << "Employee " << empl.employee << endl;
	output << "Card account:  " << empl.card_account << endl;
	output << "Salary:" << empl.salary << endl;
	return output;
}
