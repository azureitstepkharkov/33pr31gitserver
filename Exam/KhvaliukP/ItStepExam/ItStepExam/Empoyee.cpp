#include "pch.h"
#include "Empoyee.h"


Empoyee::Empoyee()
{
}

Empoyee::Empoyee(char * employee_, char * card_account_, int salary_)
{
	employee = new char[strlen(employee_) + 1];
	strcpy_s(employee, strlen(employee_) + 1, employee_);
	delete[] employee_;

	card_account = new char[strlen(card_account_) + 1];
	strcpy_s(card_account, strlen(card_account_) + 1, card_account_);
	delete[] card_account_;

	salary = salary_;
}

void Empoyee::Set_Employee(char * employee_)
{
	employee = new char[strlen(employee_) + 1];
	strcpy_s(employee, strlen(employee_) + 1, employee_);
	delete[] employee_;
}

void Empoyee::Set_CardAccount(char * card_account_)
{
	card_account = new char[strlen(card_account_) + 1];
	strcpy_s(card_account, strlen(card_account_) + 1, card_account_);
	delete[] card_account_;
}

void Empoyee::Set_Salary(int salary_)
{
	salary = salary_;
}

char * Empoyee::Get_Employee()
{
	return employee;
}

char * Empoyee::Get_CardAccount()
{
	return card_account;
}

int Empoyee::Get_Salary()
{
	return salary;
}


Empoyee::~Empoyee()
{
	delete[] employee;
	delete[] card_account;
}
