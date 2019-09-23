#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<fstream>

#include"myList.h"
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
		this->City = City;
		this->Street = Street;
		this->NumeHome = NumeHome;
		this->ApartmentNumber = ApartmentNumber;
	};
	void setNumeHome(string NumHome) { this->NumeHome = NumeHome; }
	void setStreet(string Street) { this->Street = Street; }
	void setCity(string City) { this->City = City; }
	void setApartmentNumber(int ApartmentNumber) { this->ApartmentNumber = ApartmentNumber; }

	string getCity() { return this->City = City; }
	string getStreet() { return this->Street = Street; }
	string getNumeHome() { return this->NumeHome = NumeHome; }
	int getApartmentNumber() { return this->ApartmentNumber = ApartmentNumber; }

	void Print() {
		cout << "Город: " << getCity() << endl <<
			"Улица: " << getStreet() << endl <<
			"Номер дома: " << getNumeHome() << endl <<
			"Номер квартиры или офиса: " << getApartmentNumber() << endl;
	}

	friend ostream&  operator<< (ostream& out_data, AdressInfo& p)
	{
		out_data << "Город = " << p.getCity()
			<< "Улица = " << p.getStreet()
			<< "Номер Дома = " << p.getNumeHome()
			<< "Номер квартиры или офиса = " << p.getApartmentNumber();
	}
	~AdressInfo() {};
};

class AnimalEntity
{
protected:
	string gender;
	unsigned int age;

	AnimalEntity() {};
	AnimalEntity(const AnimalEntity& obj) {};

public:
	AnimalEntity(string gender, int age)
	{
		this->gender = gender;
		this->age = age;
	}

	void setgender(string gender) { this->gender = gender; }
	void setAge(int age) { this->age = age; }

	string getgender() { return this->gender = gender; }
	int getAge() { return this->age = age; }

	void Print() {
		cout << "Пол: " << getgender() << endl <<
			"Возраст: " << getAge() << endl;
	}

	~AnimalEntity() {};
	
};

class HumanEntity : public AnimalEntity
{
protected:
	string Name;
	string Surname;

	HumanEntity() {};
	HumanEntity(const HumanEntity& obj) {};
public:

	HumanEntity(string Name, string Surname, string gender, int age) : AnimalEntity(gender, age)
	{
		this->Name = Name;
		this->Surname;
	}
	void setName(string name) { this->Name = Name; }
	string getName() { return this->Name = Name; }

	void setSurname(string sex) { this->Surname = Surname; }
	string getSurname() { return this->Surname = Surname; }

	void Print()
	{

		cout << "Имя: " << getName() << endl <<
			"Фамилия: " << getSurname() << endl;
	}

	~HumanEntity() {};
	
};

class Person : public HumanEntity
{
protected:

	string phohe;
	AdressInfo* adress;
	Person() {};
	Person(const Person& obj) {};
public:

	Person(string City, string Street, string NumeHome, int ApartamentNumber, string Name, string Surname, string gender, int age, string phone) :
		HumanEntity(Name, Surname, gender, age)
	{
		this->phohe = phone;
		this->adress = new AdressInfo(City, Street, NumeHome, ApartamentNumber);
	}

	void setphone(string phone) { this->phohe = phone; }
	string getphone() { return this->phohe = phohe; }

	friend ostream&  operator<< (ostream& out_data, Person& p)
	{
		out_data
			<< "Имя = " << p.getName()
			<< "Фамилия = " << p.getSurname()
			<< "Пол = " << p.getgender()
			<< "Возраст = " << p.getAge()
			<< "Номер телефона = " << p.getphone() << endl;
		return out_data;
	};

	/*void Print() { cout << "Телефон: " << getphone() << endl; }*/

	~Person() {};
	
};

class Employee
{
protected:
	string position;
	string CardAccount;
	double salary;

	Employee() {};
	Employee(const Employee& obj) {}
public:

	void setPosition(string position) { this->position = position; }
	void setCardAccount(string CardAccount) { this->CardAccount = CardAccount; }
	void setSalary(double salary) { this->salary = salary; }

	string getPosition() { return this->position = position;}
	string getCardAccount() { return this->CardAccount = CardAccount;}
	double getSalary() { return this->salary = salary;}

	Employee(string position, string CardAccount, double salary)
	{
		this->position = position;
		this->CardAccount = CardAccount;
		this->salary = salary;
	}

	//void Print()
	//{
	//	std::cout << "Должность: " << getPosition() << endl <<
	//		"Карточный счет: " << getCardAccount() << endl <<
	//		"Зарплата: " << getSalary() << endl;
	//}
	~Employee() {};
};

class Department : public Employee
{
private:
	string DepartName;
	list<Employee>ListOfEmployees;
	string DepartDirector;

	Department() {};
public:
	void setDepartName(string DepartName) { this->DepartName = DepartName; }
	void setDepartDirector(string DepartDirector) { this->DepartDirector = DepartDirector; }

	string getDepartName() { return this->DepartName = DepartName;}
	string getDepartDirector() { return this->DepartDirector = DepartDirector;}

	Department(string DepartName, string DepDirector, string position, string CardAccount, double salary)
		:Employee(position, CardAccount, salary)
	{
		this->DepartName = DepartName;
		this->DepartDirector = DepDirector;
	}

	friend ostream&  operator<< (ostream& out_data, Department& data)
	{
		out_data <<
			"Название отдела : " << data.getDepartName() << endl <<
			"Начальник отдела : " << data.getDepartDirector() << endl <<
			"Должность : " << data.getPosition() << endl <<
			"Банковская карта : " << data.getCardAccount() << endl <<
			"Зарплата : " << data.getSalary() << endl;
		return out_data;
	};

	//void Print()
	//{
	//	cout << "Название отдела : "  << getDepartName() << endl <<
	//		"Начальник отдела : " << getDepartDirector() << endl <<
	//		"Должность : " << getPosition() << endl <<
	//		"Банковская карта : " << getCardAccount() << endl <<
	//		"Зарплата : " << getSalary() << endl;
	//}

};
bool operator < (AdressInfo m, AdressInfo b)
{
	return m.getNumeHome() < b.getNumeHome();
};

struct SortStreetType
{
	bool operator() (AdressInfo& a, AdressInfo &b)
	{
		return a.getNumeHome() < b.getNumeHome();
	}


};

void Print(AdressInfo a)
{
	cout << a;
}
