#pragma once
#include"AnimalEntity.h"
#include<string>
using namespace std;
class HumanEntity : public AnimalEntity
{
private:
	string name;
	string surname;
public:
	HumanEntity() {};
	~HumanEntity() {};

	void setName(string name)
	{
		this->name = name;
	}

	void setSurname()
	{
		this->surname = surname;
	}

	string getName()
	{
		return name;
	}

	string getSurname()
	{
		return surname;
	}

	friend ostream& operator<< (ostream& os, HumanEntity& data)
	{
		os << "name = " << data.name << " surname = " << data.surname() << endl;
		return os;
	}

	HumanEntity(string name, string surname)
	{
		this->name = name;
		this->surname = surname;
	}

};

