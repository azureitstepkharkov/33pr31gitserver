#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <iterator> 
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
	int age;
	AnimalEntiry() {}
	AnimalEntiry(const AnimalEntiry& obj) {}
public:
	AnimalEntiry(string city, string street, string house, string flat, string phone, string adress, string name, string sname, string sex, int age) : HumanEnity(city,  street,  house,  flat, phone,  adress, name,  sname) {
		this->sex = sex;
		this->age = age;
	}
	string getSex() { return this->sex; }
	int getAge() { return this->age; }

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
	float salary;

public:
	Employee() {};
	Employee(const Employee& obj) {
		this->position = obj.position;
		this->accaunt = obj.accaunt;
		this->salary = obj.salary;
	}
	Employee(string position, string accaunt, float salary) {
		this->position = position;
		this->accaunt = accaunt;
		this->salary = salary;
	}
	string getPosition() { return this->position; }
	string getAccaunt() { return this->accaunt; }
	float setSalary() { return this->salary; }


	friend ostream&  operator<< (ostream& out_data, Employee& d)
	{
		out_data <<
			"position = " << d.getPosition() << endl <<
			"accaunt = " << d.getAccaunt() << endl <<
			"salary = " << d.setSalary() << endl;
		return out_data;
	};
};

class Department : public Employee
{
protected:
	string department;
	vector<Employee> employeers;
	string boss;
public:
	Department(string department, string boss)  {
		this->department = department;
		this->boss = boss;
	}
	string getDepartment() { return this->department; }
	string getBoss() { return this->boss; }
	void showDepartment() { cout << "Department: " << this->department << endl; }
	void showBoss() { cout << "Boss: " << this->boss << endl; }
	void setEmployeers(Employee em)
	{
		this->employeers.push_back(em);
	}
	void getEmployeers()
	{
		
		for (int i = 0; i < this->employeers.size(); i++)
		{
			cout << employeers[i];
		}
	}
	friend ostream&  operator<< (ostream& out_data, Department& d)
	{
		out_data <<
			"position = " << d.getPosition() << endl <<
			"accaunt = " << d.getAccaunt() << endl <<
			"salary = " << d.setSalary() << endl <<
			"department = " << d.getDepartment() << endl <<
			"boss = " << d.getBoss() << endl;
		return out_data;
	};
};

int main()
{
	std::cout << "Hello World!\n";
	AnimalEntiry a("Kharkov", "street 45", "house 21 ", "flat 34", "phone 67567", "adress 34", "Kirill", "zubakha",  "male",  25);
	cout << a << endl; 

	Department d("IT","BOSS");
	d.setEmployeers(Employee("developer", "241324", 10));
	d.setEmployeers(Employee("manager", "1232", 50));
	d.setEmployeers(Employee("developer", "55555", 10));
	d.setEmployeers(Employee("manager", "777", 10));
	d.setEmployeers(Employee("developer", "24984", 10));
	d.setEmployeers(Employee("manager", "2954279", 10));
	d.setEmployeers(Employee("developer", "82484", 10));
	d.setEmployeers(Employee("dizign", "984289", 10));
	d.setEmployeers(Employee("developer", "894298", 10));
	d.setEmployeers(Employee("devoops", "982498", 10));
	d.setEmployeers(Employee("developer", "21434", 10));
	d.setEmployeers(Employee("devoops", "9494", 10));
	d.showBoss();
	
	d.showDepartment();
	
	d.getEmployeers();
	
}