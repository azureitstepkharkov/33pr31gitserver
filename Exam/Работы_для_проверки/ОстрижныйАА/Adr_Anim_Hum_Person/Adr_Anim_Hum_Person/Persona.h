#pragma once
#include"Adress.h"

class Person
{
protected:
	string Adress;
	string Phone;
public:
	Person() {};

	Person(string Adress, string Phone)
	{
		this->Adress = Adress;
		this->Phone = Phone;
	};

	void Print()
	{
		std::cout << "Адрес: " << Adress << endl <<
			"Номер телефона: " << Phone << endl;
	}

	string set_Adress(string Adress) { this->Adress = Adress; }
	string set_Phone(string Phone) { this->Phone = Phone; }

	string get_Adress() { return this->Adress; }
	string get_Phone() { return this->Phone; }

	~Person() {};
};
