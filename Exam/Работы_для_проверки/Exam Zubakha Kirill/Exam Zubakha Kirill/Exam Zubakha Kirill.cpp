#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AdressInfo 
{
protected:
	string city;
	string street;
	string house;
	string flat;// стринги потому, что может быть с буквой "21в"
	AdressInfo() {}
	AdressInfo(const AdressInfo& obj) {}
public:
	AdressInfo(string city, string street, string house, string flat) 
	{
		this->city= city;
		this->street= street;
		this->house= house;
		this->flat= flat;
	}
	string getCity () { return this->city; }
	string getStreet() { return this->street; }
	string getHouse() { return this->house; };
	string getFlat() { return this->flat; };
};

class Person : public AdressInfo
{
protected:
	string phone;
	string adress;
	Person() {}
	Person(const Person& obj) {}
public:
	Person(string city, string street, string house, string flat, string phone, string adress) : AdressInfo(city, street, house, flat)
	{
		this->phone = phone;
		this->adress = adress;
	}
	string getPhone() { return this->phone; }
	string getAdress() { return this->adress; }
};

class  HumanEnity : public Person
{
protected:
	string name;
	string sname;
	HumanEnity() {}
	HumanEnity(const HumanEnity& obj) {}
public:
	HumanEnity (string city, string street, string house, string flat, string phone, string adress, string name, string sname):Person(city,  street,  house,  flat, phone,  adress)
	{
		this->name = name;
		this->sname = sname;
	}
	string getName() { return this->name; }
	string getSname() { return this->sname; }
};

class AnimalEntiry : public HumanEnity
{
protected:
	string sex;
	string age;
	AnimalEntiry() {}
	AnimalEntiry(const AnimalEntiry& obj) {}
public:
	AnimalEntiry(string city, string street, string house, string flat, string phone, string adress, string name, string sname, string sex, string age) : HumanEnity(city,  street,  house,  flat, phone,  adress, name,  sname) {
		this->sex = sex;
		this->age = age;
	}
	string getSex() { return this->sex; }
	string getAge() { return this->age; }

	friend ostream&  operator<< (ostream& out_data, AnimalEntiry& a)
	{
		out_data <<
			"city = " << a.getCity() << endl <<
			"street = " << a.getStreet() << endl <<
			"house = " << a.getHouse() << endl <<
			"flat = " << a.getFlat() << endl <<
			"phone = " << a.getPhone() << endl <<
			"adress = " << a.getAdress() << endl <<
			"name = " << a.getName() << endl <<
			"sname = " << a.getSname() << endl <<
			"sex = " << a.getSex() << endl <<
			"age = " << a.getAge() <<	endl;

			return out_data;
	};
};

class Employee
{
protected:
	string position;
	string accaunt;
	string salary;

public:
	Employee() {}
	Employee(const Employee& obj) {}
	Employee(string position, string accaunt, string salary) {
		this->position = position;
		this->accaunt = accaunt;
		this->salary = salary;
	}
	string getPosition() { return this->position; }
	string getAccaunt() { return this->accaunt; }
	string setSalary() { return this->salary; }
};

class Department : public Employee
{
protected:
	string department;
	string employee;
	//Employee employee;
	string boss;
public:
	Department(string position, string accaunt, string salary, string department, /*Employee employee,*/ string employee, string boss) : Employee(position, accaunt, salary) {
		this->department = department;
		/*Employee **kart = new Employee*[2];
		for (int i = 0; i < 2; i++)
		{
			Employee* employee = new Employee;
			this->employee;
			kart[i] = employee;
		}*/
		this->employee = employee;
		this->boss = boss;
	}
	string getDepartment() { return this->department; }
	string getEmployee() { return this->employee; }
	string getBoss() { return this->boss; }

	friend ostream&  operator<< (ostream& out_data, Department& d)
	{
		out_data <<
			"position = " << d.getPosition() << endl <<
			"accaunt = " << d.getAccaunt() << endl <<
			"salary = " << d.setSalary() << endl <<
			"department = " << d.getDepartment() << endl <<
			"employee = " << d.getEmployee() << endl <<
			"boss = " << d.getBoss() << endl;
		return out_data;
	};
};

int main()
{
	std::cout << "Hello World!\n";
	AnimalEntiry a("Kharkov", "street 45", "house 21 ", "flat 34", "phone 67567", "adress 34", "Kirill", "zubakha",  "male",  "25 years");
	cout << a << endl; 

	std::cout << "Hello World 2!\n";
	Department d("position", "accaunt 45", "salary 21 ", "department 34", "employee 67567", "boss 34");
	cout << d << endl;
}