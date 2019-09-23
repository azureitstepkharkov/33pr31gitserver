
#pragma once
#include"Adress.h"

class HumanEntity
{
protected:
	string Name;
	string Sname;
public:
	HumanEntity() {};

	HumanEntity(string name, string Sname)
	{
		this->Name = name;
		this->Sname = Sname;
	};

	void Print()
	{
		std::cout << "Имя: " << Name << endl <<
			"Фамилие: " << Sname << endl;
	}

	string set_name(string name) { this->Name = name; }
	string set_Sname(string Sname) { this->Sname = Sname; }

	string get_name() { return this->Name; }
	string get_Sname() { return this->Sname; }

	~HumanEntity() {};
};
