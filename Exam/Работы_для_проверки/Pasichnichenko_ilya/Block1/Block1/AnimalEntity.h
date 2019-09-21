#pragma once
#include<string>
using namespace std;
class AnimalEntity
{
protected:
	int age;
	string sex;

	AnimalEntity() {}
	AnimalEntity(const AnimalEntity& obj) {}
public:

	void setAge(int age){this->age = age;}
	void setSex(string sex){this->sex = sex;}

	int getAge(){return age;}
	string getSex(){return sex;}

	AnimalEntity(int age, string sex)
	{
		this->age = age;
		this->sex = sex;
	}

};