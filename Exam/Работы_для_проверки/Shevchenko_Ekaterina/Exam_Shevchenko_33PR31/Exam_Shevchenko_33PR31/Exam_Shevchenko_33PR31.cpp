// Exam_Shevchenko_33PR31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>
using namespace std;

class AdressInfo
{
protected:
	string City;
	string TypeStreet;
	string Street;
	string HouseHumber;
	unsigned int OfficeOrApartmentNum;
AdressInfo() {};
AdressInfo(AdressInfo& adr) {};
public:
	AdressInfo(string Ct, string TpStrt, string Strt, string housNm, unsigned int OfAptmNm)
	{
		this->City = Ct;
		this->TypeStreet = TpStrt;
		this->Street = Strt;
		this->HouseHumber = housNm;
		this->OfficeOrApartmentNum = OfAptmNm;
	}
	
	friend ostream& operator<<(ostream& out_data, AdressInfo& data)
	{
		out_data << data.City << " " << data.TypeStreet << " " << data.Street
			<< " " << data.HouseHumber << " " << data.OfficeOrApartmentNum << endl;
		return out_data;
	}
	void set_city(string Ct) { this->City = Ct; }
	void set_typestreet(string tpStrt) { this->TypeStreet = tpStrt; }
	void set_street(string strt) { this->Street = strt; }
	void set_housenum(string housnm) { this->HouseHumber = housnm; }
	void set_apartmentnum(unsigned int OfAptNum) { this->OfficeOrApartmentNum = OfAptNum; }
	string get_city() { return this->City;}
	string get_typestreet() { return this->TypeStreet; }
	string get_street() { return this->Street; }
	string get_housenum() { return this->HouseHumber; }
	unsigned int get_apartmentnum() { return this->OfficeOrApartmentNum; }
	~AdressInfo() {};

};

class AnimalEntity
{
protected:
	string sex;
	unsigned int age;
	AnimalEntity() {};
	AnimalEntity(AnimalEntity& anim) {};
public:
	AnimalEntity(string sex, unsigned int age)
	{
		this->sex = sex;
		this->age = age;
	}
	
	friend ostream& operator<<(ostream& out_data, AnimalEntity& data)
	{
		out_data << data.sex << " " << data.age << endl;
		return out_data;
	}
	void set_sex(string sex) { this->sex = sex; }
	void set_age(unsigned int age) { this->age = age; }
	string get_sex() { return this->sex; }
	unsigned int get_age() { return this->age; }
	~AnimalEntity() {};
};

class HumanEntity:AnimalEntity
{
protected:
	string Name;
	string Surname;
public:
    HumanEntity() {};
	HumanEntity(HumanEntity& human) {};
public:
	HumanEntity(string name, string surname, string sex, unsigned int age):AnimalEntity(sex, age)
	{
		this->Name = name;
		this->Surname = surname;
	
	}
	friend ostream& operator<<( ostream& out_data, HumanEntity& data)
	{
		out_data << data.Name << " " << data.Surname << endl;
		return out_data;
	}
	void set_name(string name) { this->Name = name; }
	void set_sname(string sname) { this->Surname = sname; }
	string get_name() { return this->Name; }
	string get_sname() { return this->Surname; }
	~HumanEntity() {};
};


class Person:HumanEntity
{
protected:
	string phone;
	AdressInfo* adress;
	Person() {};
	Person(Person& per) {};
	public:
	Person(string phone, string ct, string tpstrt, string strt, string hsnum, unsigned int apart, string name, string surname, string sex, unsigned int age)
		:HumanEntity(name, surname, sex, age)
	{
		this->phone = phone;
		this->adress =new AdressInfo(ct, tpstrt, strt, hsnum, apart);
	}
	friend ostream& operator<<(ostream& out_data, Person& data)
	{
		out_data << data.phone << " " << data.adress << " " << data.Name << " " << data.Surname << endl;
		
		return out_data;
	}
	~Person() {};
};


class Employee:Person
{
protected:
	string Position;
	string BankAccount;
	string Salary;
	Employee() {};
	Employee(Employee& emp) {};
public:
	Employee(string pos, string acc, string salary,string phone, string ct, string tpstrt, string strt, string hsnum,
			unsigned int apart, string name, string surname, string sex, unsigned int age)
				:Person(phone, ct, tpstrt, strt, hsnum, apart, name, surname, sex, age)
	{
		this->Position = pos;
		this->BankAccount = acc;
		this->Salary = salary;
	}
	friend ostream& operator<<(ostream& out_data, Employee& data)
	{
		out_data << data.Position << " " << data.BankAccount << " " << data.Salary
			<< endl; 
		return out_data;
	}
	~Employee() {};
};

class Department
{
protected:
	string DepartmentName;
	Employee* EmployeesList;
	HumanEntity* Cheif;
	Department() {};
	Department(Department& dep) {};
public:
	Department(string depname, string pos, string acc, string salary, string phone, string ct, string tpstrt, string strt, string hsnum,
		unsigned int apart, string name, string surname, string sex, unsigned int age)
	{
		this->DepartmentName = depname;
		this->EmployeesList = new Employee("designer", "5148755423119142", "12000 UAN", "+380994597228", "Kharkov", "street",
			"Sumskaya", "45a", 84, "Aleksandr", "Petrov", "male", 23);
		this->Cheif = new HumanEntity("Maksim", "Andreenko", "male", 35);
	};
	friend ostream& operator<<(ostream& out_data, Department& data)
	{
		out_data << data.DepartmentName << " " << data.EmployeesList << " " << data.Cheif
			<< endl;
		return out_data;
	}
	~Department() {};
};
int main()
{
   cout << "My Exam!!!\n"; 

   Person a("+380994597228", "Kharkov", "street", "Sumskaya", "45a", 84, "Aleksandr", "Petrov", "male", 23);

   cout << a;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
