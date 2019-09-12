// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>

using namespace std;

class AdressInfo
{
protected:
	string City;
	string Street;
	string NumeHome;
	unsigned int ApartmentNumber;

	AdressInfo() {};
	AdressInfo(const AdressInfo& obj) {};
public:
	AdressInfo(string City, string Street, string NumeHome, int ApartamentNumber)
	{
		setCity(City);
		setStreet(Street);
		this->NumeHome = NumeHome;
		this->ApartmentNumber = ApartmentNumber;
	};
	
	void setCity(string City) { this->City = City; }
	string getCity() { return this->City = City; }

	void setStreet(string sex) { this->Street = Street; }
	string getStreet() { return this->Street = Street; }

	void setNumeHome(int age) { this->NumeHome = NumeHome; }
	string getNumeHome() { return this->NumeHome = NumeHome; }

	void setApartmentNumber(int ApartmentNumber)
	{
		this->ApartmentNumber = ApartmentNumber;
	}
	int getApartmentNumber()
	{
		return this->ApartmentNumber = ApartmentNumber;
	}
};

class AnimalEntity
{
protected:
	string name;
	string sex;
	unsigned int age;

	AnimalEntity() {};
	AnimalEntity(const AnimalEntity& obj) {};

public:
	AnimalEntity(string name,string sex, int age)
	{
		setName(name);
		setSex(sex);
		this->age = age;
	}

	void setName(string name) { this->name = name; }
	string getName() { return this->name = name; }

	void setSex(string sex) { this->sex = sex; }
	string getSex() { return this->sex = sex; }

	void setAge(int age) { this->age = age; }
	int getAge() { return this->age = age; }
	
};

class HumanEntity : public AnimalEntity
{
protected:
	string Name;
	string Surname;

	HumanEntity() {};
	HumanEntity(const HumanEntity& obj) {};
public:

	HumanEntity(string name, string sex, int age, string Name, string Surname): AnimalEntity(name, sex, age)
	{
		setName(Name);
		setSurname(Surname);
	}
	void setName(string name) { this->Name = Name; }
	string getName() { return this->Name = Name; }

	void setSurname(string sex) { this->Surname = Surname; }
	string getSurname() { return this->Surname = Surname; }

};

class Person : public AdressInfo, public HumanEntity
{
protected:

	string phohe;
	AdressInfo* Adres;

	Person() {};
	Person(const Person& obj) {};
public:

	Person(string City, string Street, string NumeHome, int ApartamentNumber, string name, string sex, int age, string Name, string Surname, string phone):
		AdressInfo(City,Street, NumeHome, ApartamentNumber), HumanEntity( name,  sex,  age,  Name, Surname)
	{
		this->phohe = phone;
		this->Adres = new AdressInfo(City,Street, NumeHome, ApartamentNumber);
	}



	//friend ostream&  operator<< (ostream& out_data, AnimalEntity& p)
	//{
	//	out_data << "name = " << p.getName() << "sex = " << p.getSex() << " age = " << p.getAge() << endl;
	//	return out_data;
	//};
};

class Employee
{
protected:
	string position;
	unsigned int card_account;
	double salary;
	Employee() {};
	Employee(const Employee& obj) {};

public:
	Employee(string position, int card_account, double salary)
	{
		this->position = position;
		this->card_account = card_account;
		this->salary = salary;
	}
};

class Departament
{
protected:
	string department_name;
	string list_of_employees;
	string Chief;
public:

};
int main()
{
	
	system("pause");
    return 0;
}

