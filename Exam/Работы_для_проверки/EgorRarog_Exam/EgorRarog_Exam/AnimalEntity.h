#pragma once
#include"AdressInfo.h"
#include<string>
#include<iostream>
using namespace std;
class AnimalEntity : public AdressInfo
{
protected:
	string sex;
	int age;
	AnimalEntity() { cout << "const AnimalEntity& obj" << endl; };
	AnimalEntity(const AnimalEntity& obj) { cout << "const AnimalEntity& obj" << endl; };
	~AnimalEntity() {};
public:
	AnimalEntity(string _sex, int _age) {
		this->age = _age;
		this->sex = _sex;
	}
	void setSex(string info) { this->sex = info; }
	void setAge(int age) { this->age = age; }
	string getSex() { return sex; }
	int getAge() { return age; }

	friend ostream& operator << (ostream& out_data, AnimalEntity& a)
	{
		out_data << "Sex is " << a.sex << endl;
		out_data << "Age is" << a.age << endl;

		return out_data;
	};

	friend class HumanEntity;
};

