#pragma once
class Empoyee
{
protected:
	char* employee;
	char* card_account;
	int salary;
public:
	Empoyee();
	Empoyee(char* employee_, char* card_account_, int salary_);
	void Set_Employee(char* employee_);
	void Set_CardAccount(char* card_account_);
	void Set_Salary(int salary_);
	char* Get_Employee();
	char* Get_CardAccount();
	int Get_Salary();
	~Empoyee();
};

