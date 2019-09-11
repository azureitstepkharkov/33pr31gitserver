#pragma once
#include"AdressInfo.h"

class AnimalEntity
{
protected:
	string Pol;
	string age;
public:
	AnimalEntity() {};

	AnimalEntity(string Pol, string age)
	{
		this->Pol = Pol;
		this->age = age;
	};

	void Print()
	{
		std::cout << "Пол: " << Pol << endl << 
			"Возраст: " << age << endl;
	}

	string set_pol(string Pol) { this->Pol = Pol; }
	string set_age(string age) { this->age = age; }

	string get_pol() { return this->Pol; }
	string get_age() { return this->age; }

	~AnimalEntity() {};
};

