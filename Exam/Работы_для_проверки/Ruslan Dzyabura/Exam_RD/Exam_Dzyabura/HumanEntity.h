#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include<string>
#include<iostream>
using namespace std;
class HumanEntity : public AnimalEntity
{
protected:
	string surname;
	string name;
	HumanEntity() { cout << "call HumanEntity()" << endl; };
	HumanEntity(const HumanEntity& obj) { cout << "const HumanEntity& obj" << endl; };
	~HumanEntity() {};
public:
	HumanEntity(string name,string surname) {
		this->name = name;
		this->surname = surname;
	}
	void setTel_num(string info) { this->name = info; }
	void setAdr(string surname) { this->surname = surname; }
	string getName() { return name; }
	string getSurname() { return surname; }
	friend ostream& operator << (ostream& out_data, HumanEntity& h)
	{
		out_data << "Name is " << h.name << endl;
		out_data << "Surname is" <<h.surname << endl;

		return out_data;
	};

	friend class Person;
};

