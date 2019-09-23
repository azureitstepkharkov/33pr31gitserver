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
#include"SalaryCalc.h"
using namespace std;

////////////////////
//
//struct ISalaryCalculator
//{
//	virtual double calcSalary() = 0;
//};
////1 - оклад
//class Rule1 : public ISalaryCalculator
//{
//protected:
//	double base;
//public:
//	Rule1() { base = 0; }
//	Rule1(double base) { this->base = base; }
//	virtual double calcSalary()
//	{
//		return base;
//	}
//};
//
////2 - оплата по часам
//class Rule2 : public ISalaryCalculator
//{
//protected:
//	double hour;
//	double rate;
//public:
//	Rule2() { hour = 0; rate = 0; }
//	Rule2(double hour, double rate) { this->hour = hour; this->rate = rate; }
//	virtual double calcSalary()
//	{
//		return hour * rate;
//	}
//};
//
////3 - оплата с бонусами //изменить под процент от выручки
//class Rule3 : public ISalaryCalculator
//{
//protected:
//	double base;
//	double percent;
//	double bonus;
//public:
//	Rule3() { base = 0; percent = 0; bonus = 0; }
//	Rule3(double base, double percent, double bonus)
//	{
//		this->base = base; this->percent = percent; this->bonus = bonus;
//	}
//	virtual double calcSalary()
//	{
//		return base + base * percent + bonus;
//	}
//};
//
//struct CalcInfo
//{
//	double base;//база - оклад
//	double percent;//значение %
//	double total;//сумма продаж или 
//	double bonus;//бонус
//	double bonus_percent;//процент бонуса
//	double hour;//количество часов
//	double rate_per_hour;//стоимость часа
//};
//
////////////
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

class HumanEntity: public AnimalEntity
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
		out_data << data.Name << " " << data.Surname << " " << data.age << " " << data.sex << endl;
		return out_data;
	}
	void set_name(string name) { this->Name = name; }
	void set_sname(string sname) { this->Surname = sname; }
	string get_name() { return this->Name; }
	string get_sname() { return this->Surname; }
	~HumanEntity() {};
};


class Person: public HumanEntity
{
protected:
	string phone;
	AdressInfo* adress;
	Person() {};
	Person(Person& per) {};
	public:
	Person(string phone, string ct, string tpstrt, string strt, string hsnum, unsigned int apart, 
		string name, string surname, string sex, unsigned int age)
		:HumanEntity(name, surname, sex, age)
	{
		this->phone = phone;
		this->adress =new AdressInfo(ct, tpstrt, strt, hsnum, apart);
	}
	friend ostream& operator<<(ostream& out_data, Person& data)
	{
		out_data << data.Name << " " << data.Surname << " " << data.phone << " " <<
			data.adress->get_city() << " " << data.adress->get_typestreet() << " " <<
			data.adress->get_street() << " " << data.adress->get_housenum() << " "
			<< data.adress->get_apartmentnum() << " " << data.get_sex()
			<< " " << data.get_age() << endl;
		
		return out_data;
	}
	~Person() {};
};


class Employee: public Person, public ISalaryCalculator
{
protected:
	string Position;
	string BankAccount;
	//string Salary;

	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или бонус
	double hour;//количество часов
	double rate_per_hour;

	ISalaryCalculator* salaryCalc;

	
	Employee(Employee& emp) {};
public:
	Employee() {};
	Employee(string pos, string acc, string salary,string phone, string ct, string tpstrt, string strt, string hsnum,
			unsigned int apart, string name, string surname, string sex, unsigned int age)
				:Person(phone, ct, tpstrt, strt, hsnum, apart, name, surname, sex, age)
	{
		this->Position = pos;
		this->BankAccount = acc;
		//this->Salary = salary;
	}
	friend ostream& operator<<(ostream& out_data, Employee& data)
	{
		out_data <<data.Name << " "<< data.Surname << " " << data.phone << " " <<
			data.adress->get_city() << " " << data.adress->get_typestreet() << " " <<
			data.adress->get_street() << " " << data.adress->get_housenum() << " "
			<< data.adress->get_apartmentnum() << " " << data.get_sex()
			<< " " << data.get_age() << data.Position << " " << data.BankAccount /*<<
			" " << data.Salary << " "*/ << endl;
		return out_data;
	}
	//////////////////////////////////

	
	//"универсальный" конструктор
	Employee(string pos, string acc, string phone, string ct, string tpstrt, 
		string strt, string hsnum,unsigned int apart, string name, string surname, string sex,
		unsigned int age, int codePosition, CalcInfo info)
		:Person(phone, ct, tpstrt, strt, hsnum, apart, name, surname, sex, age)
	{
		this->BankAccount = acc;
		this->Position = pos;
		this->base = info.base;
		this->total = info.bonus;
		this->percent = info.percent;
		this->hour = info.hour;
		this->rate_per_hour = info.rate_per_hour;
		this->salaryCalc = createSalarycalcRule(codePosition, info);
	}
	static ISalaryCalculator* createSalarycalcRule(int codePosition, CalcInfo info)
	{
		ISalaryCalculator* salaryCalc = NULL;
		switch (codePosition)
		{
		case 1: salaryCalc = new Rule1(info.base); break;
		case 2: salaryCalc = new Rule2(info.hour, info.rate_per_hour); break;
		case 3: salaryCalc = new Rule3(info.base, info.percent, info.bonus);
			break;
		default: salaryCalc = new Rule1(info.base);
			break;
		}
		return salaryCalc;
	}

	///////////////////////////////

	~Employee() {};
};

//Employee vector;

class Department/*:public Employee, public ISalaryCalculator*/
{
protected:
	string DepartmentName;
	//Employee* EmployeesList;
	vector<Employee>employees;
	HumanEntity* Cheif;
	Department() {};
	Department(Department& dep) {};
public:
	Department(Employee vect, string depname, string pos, string acc, string phone, string ct, string tpstrt,
		string strt, string hsnum, unsigned int apart, string name, string surname, string sex,
		unsigned int age, int codePosition, CalcInfo info)
	{
		this->DepartmentName = depname;
		 
		/*this->EmployeesList = new Employee(pos, acc,
			phone, ct, tpstrt,
			strt, hsnum, apart, name , surname, sex, age, codePosition, info);*/
		this->Cheif = new HumanEntity(name, surname, sex, age);
	};
	friend ostream& operator<<(ostream& out_data, Department& data)
	{
		out_data << data.DepartmentName  /*" " << data.EmployeesList <<*/ << " " << data.Cheif
			<< endl;
		return out_data;
	}
	~Department() {};
};

//class EmployeeSalary : public HumanEntity, public ISalaryCalculator
//{
//protected:
//	//составляющие части зп для расчета:
//	double base;//база - оклад
//	double percent;//значение %
//	double total;//сумма продаж или бонус
//	double hour;//количество часов
//	double rate_per_hour;//стоимость часа
//	//вопрос: а нужно ли их здесь вообще хранить?
//	string position;//название должности
//	ISalaryCalculator* salaryCalc;//механизм расчета ЗП
//	//конструктор по умолчанию
//	//Employee() { salaryCalc = NULL; }
//	//копирующий конструктор по умолчанию
//	//Employee(const Employee& obj) {}
//public:
//	//
//	virtual double calcSalary()
//	{
//		if (this->salaryCalc == NULL)
//			return 0;
//		else
//			return this->salaryCalc->calcSalary();
//	}
	/*
	virtual ~Employee()
	{
		if (salaryCalc != NULL)
		{
			delete salaryCalc;
		}
	}
	*/
	////конструктор для должностей с оплатой по правилу 1
	//EmployeeSalary(string name, string surname, string sex, unsigned int age, string position, double base)
	//	: HumanEntity(name, surname, sex, age)
	//{
	//	this->position = position;
	//	this->base = base;
	//	this->hour = 0;
	//	this->rate_per_hour = 0;
	//	this->percent = 0;
	//	this->total = 0;
	//	this->salaryCalc = new Rule1(base);
	//}
	////конструктор для должностей с оплатой по правилу 2
	//EmployeeSalary(string name, string surname, string sex, unsigned int age, string position, double h, double rate)
	//	:HumanEntity(name,  surname,  sex, age)
	//{
	//	this->position = position;
	//	this->hour = h;
	//	this->rate_per_hour = rate;
	//	this->percent = 0;
	//	this->total = 0;
	//	this->base = 0;
	//	this->salaryCalc = new Rule2(this->hour, this->rate_per_hour);
	//}
	////конструктор для должностей с оплатой по правилу 3
	//EmployeeSalary(string name, string surname, string sex, unsigned int age, string position, double base, double percent, double bonus)
	//	: HumanEntity(name, surname, sex, age)
	//{
	//	this->position = position;
	//	this->base = base;
	//	this->total = bonus;
	//	this->percent = percent;
	//	this->hour = 0;
	//	this->rate_per_hour = 0;
	//	this->salaryCalc = new Rule3(base, percent, bonus);
	//}
	////"универсальный" конструктор
	//EmployeeSalary(string name, string surname, string sex, unsigned int age, string position, int codePosition, CalcInfo info)
	//	:HumanEntity(name, surname, sex, age)
	//{
	//	this->position = position;
	//	this->base = info.base;
	//	this->total = info.bonus;
	//	this->percent = info.percent;
	//	this->hour = info.hour;
	//	this->rate_per_hour = info.rate_per_hour;
	//	this->salaryCalc = createSalarycalcRule(codePosition, info);
	//}
	//static ISalaryCalculator* createSalarycalcRule(int codePosition, CalcInfo info)
	//{
	//	ISalaryCalculator* salaryCalc = NULL;
	//	switch (codePosition)
	//	{
	//	case 1: salaryCalc = new Rule1(info.base); break;
	//	case 2: salaryCalc = new Rule2(info.hour, info.rate_per_hour); break;
	//	case 3: salaryCalc = new Rule3(info.base, info.percent, info.bonus);
	//		break;
	//	default: salaryCalc = new Rule1(info.base);
	//		break;
	//	}
	//	return salaryCalc;
	//}
	////перегрузка обязательных операторов
	//friend ostream& operator<< (ostream& os, EmployeeSalary& data)
	//{
	//	os << "name = " << data.get_name() << " position = " << data.position
	//		<< " salary = " << data.calcSalary() << endl;
	//	return os;
	//}
	////
//};
int main()
{
   cout << "My Exam!!!\n"; 

   Person a("+380994597228", "Kharkov", "street", "Sumskaya", "45a", 84, "Aleksandr", "Petrov", "male", 23);

   CalcInfo info1;
   info1.base = 7500;
   info1.percent = 15;
   info1.bonus = 100000;

   Employee b("Programmer", "5168755434678912", "0994567132", "Kharkov", "prospect", "Moskovskiy", "248a", 47,
	   "Andrey", "Ivanov", "man", 25, 2, info1);

   cout << a;


   vector<Employee>employees(50);
   int m = employees.size();
  
   //Я старалась, но я запуталась и хочу спать... =(
   
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
