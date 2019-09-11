#pragma once
#include<string>
using namespace std;
class AnimalEntity
{
protected:
	int age;
	string sex;
public:

	void setAge(int age)
	{
		if (age > 0)
			this->age = age;
	}

	void setSex(string sex)
	{
		this->sex = sex;
	}

	int getAge()
	{
		return age;
	}

	string getSex()
	{
		return sex;
	}

	AnimalEntity(int age, string sex)
	{
		this->age = age;
		this->sex = sex;
	}

	friend ostream& operator<< (ostream& os, AnimalEntity& data)
	{
		os << "age = " << data.age << " sex = " << data.sex << endl;
		return os;
	}

	AnimalEntity() {}
	~AnimalEntity() {};

};

