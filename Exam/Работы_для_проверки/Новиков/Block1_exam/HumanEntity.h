#pragma once
#include"AnimalEntity.h"
#include<string>
using namespace std;
class HumanEntity : public AnimalEntity
{
protected:
	string name;
	string surname;

	HumanEntity(const HumanEntity& obj) {}
	HumanEntity() {};
public:

	void setName(string name) { this->name = name; }
	void setSurname() { this->surname = surname; }

	string getName() { return name; }
	string getSurname() { return surname; }


	HumanEntity(string name, string surname, int age, string sex)
		:AnimalEntity(age, sex)
	{
		this->name = name;
		this->surname = surname;
	}

};