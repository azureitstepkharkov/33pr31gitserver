#pragma once
#include<string>
using namespace std;
class AnimalEntity
{
protected:
	int age;
	string gender;

	AnimalEntity() {}
	AnimalEntity(const AnimalEntity& obj) {}
public:

	void setAge(int age) { this->age = age; }
	void setSex(string sex) { this->gender = sex; }

	int getAge() { return age; }
	string getSex() { return gender; }

	AnimalEntity(int age, string sex)
	{
		this->age = age;
		this->gender = sex;
	}

};
