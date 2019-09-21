#pragma once
#include"Adress.h"

class Employee
{
protected:
	string position;
	string card_account;
	string salary;
public:
	Employee() {};

	Employee(string position, string card_account, string salary)
	{
		this->position = position;
		this->card_account = card_account;
		this->salary = salary;
	};

	void Print()
	{
		std::cout << "Должность: " << position << endl <<
			"Карточный счет: " << card_account << endl <<
			"Зарплата: " << salary << endl;
	}

	string set_position(string position) { this->position = position; }
	string set_card_account(string card_account) { this->card_account = card_account; }
	string set_salary(string salary) { this->salary = salary; }

	string get_position() { return this->position; }
	string get_card_account() { return this->card_account; }
	string get_salary() { return this->salary; }

	~Employee() {};
};
