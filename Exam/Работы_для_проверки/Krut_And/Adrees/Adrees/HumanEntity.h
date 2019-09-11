#pragma once
#include"AdressInfo.h"

class HumanEntity
{
protected:
	string name;
	string familie;
public:
	HumanEntity() {};

	HumanEntity(string name, string familie)
	{
		this->name = name;
		this->familie = familie;
	};

	void Print()
	{
		std::cout << "Имя: " << name << endl << 
			"Фамилие: " << familie << endl;
	}

	string set_name(string name) { this->name = name; }
	string set_familie(string familie) { this->familie = familie; }

	string get_name() { return this->name; }
	string get_familie() { return this->familie; }

	~HumanEntity() {};
};