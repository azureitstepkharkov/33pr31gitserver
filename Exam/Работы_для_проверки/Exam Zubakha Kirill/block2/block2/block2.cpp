// SalaryCalculatorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};
//оклад + преми€
class Rule1 : public ISalaryCalculator
{
protected:
	double salary;
	double premium;
public:

	Rule1()
	{
		this->salary = 0;
		this->premium = 0;
	}
	Rule1(double salary, double premium)
	{
		this->salary = salary;
		this->premium = premium;
	}
	virtual double calcSalary()
	{
		return salary;
		return premium;
	}
};
//ѕочасовка
class Rule2 : public ISalaryCalculator
{
protected:
	double hours;
	double payment;
public:
	Rule2() { this->hours = 0; this->payment = 0; }
	Rule2(double hours, double payment)
	{
		this->hours = hours;
		this->payment = payment;
	}
	virtual double calcSalary()
	{
		return this->hours * this->payment;
	}
};
//база + % от выручки
class Rule3 : public ISalaryCalculator
{
protected:
	double base;
	double total;
	double percent;
public:
	virtual double calcSalary()
	{
		return this->base + this->total * this->percent;
	}
	Rule3() { this->base = 0; this->total = 0; this->percent = 0; }
	Rule3(double base, double percent, double total)
	{
		this->base = base;
		this->percent = percent;
		this->total = total;
	}
};

class ManPerson
{
protected:

	ManPerson() {}
	ManPerson(const ManPerson& obj) {}
public:
	string name;
	int age;
	ManPerson(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string getName() { return this->name; }
	int getAge() { return this->age; }

};
//все данные, которык могут понадобитс€ дл€ расчета «ѕ
struct CalcInfo
{
	double salary;
	double premium;
	double hours;
	double payment;
	double base;
	double total;
	double percent;
};
class Employee : public ManPerson, public ISalaryCalculator
{
protected:

	double salary;
	double premium;
	double hours;
	double payment;
	double base;
	double total;
	double percent;
	ISalaryCalculator* salaryCalculator;
	string position;
public:

	Employee(string name, int age, string position, double salary, double premium) :ManPerson(name, age)
	{
		this->name = name;
		this->age = age;
		this->premium = premium;
		this->salary = salary;
		salaryCalculator = new Rule1(salary, premium);
	}
	Employee(string name, int age, string position, double hours, double payment) :ManPerson(name, age)
	{
		this->name = name;
		this->age = age;
		this->hours = hours;
		this->payment = payment;
		salaryCalculator = new Rule2(hours, payment);
	}
	Employee(string name, int age, string position, double base, double percent, double total) :ManPerson(name, age)
	{

		this->name = name;
		this->age = age;
		this->base = base;
		this->total = total;
		this->percent = percent;

		salaryCalculator = new Rule3(base, percent, total);
	}

	Employee(string name, int age, string position, int codePosition, CalcInfo info) :ManPerson(name, age)
	{
		this->name = name;
		this->age = age;
		this->position = position;
		this->base = info.base;
		this->total = info.total;
		this->hours = info.hours;
		this->percent = info.percent;
		this->salary = info.salary;
		this->premium = info.premium;
		this->payment = info.payment;

		this->salaryCalculator = createSalaryCalculator(codePosition, info);
	}
	static ISalaryCalculator* createSalaryCalculator(int codePosition, CalcInfo info)
	{
		ISalaryCalculator* salaryCalculator = NULL;
		switch (codePosition)
		{
		case 1: salaryCalculator = new Rule1(info.premium, info.salary); break;
		case 2: salaryCalculator = new Rule2(info.hours, info.payment); break;
		case 3:salaryCalculator = new Rule3(info.base, info.percent, info.total); break;
		default: salaryCalculator = new Rule1(info.premium, info.salary);
			break;
		}
		return salaryCalculator;
	}
	
	virtual double calcSalary()
	{
		return this->salaryCalculator->calcSalary();
	}
};

//€ пыталс€, но понимаю далеко не все 

int main()
{
	std::cout << "Salary Calculator test:\n";
	const int N = 4;
	Employee** employees = new Employee*[N];
	employees[0] = new Employee("Ivan Petrov", 25, "Programmer", 160, 6.25);
	employees[1] = new Employee("Anna Ivanova", 75, "Cleaner Manger", 80, 35);
	employees[2] = new Employee("Liliya Petrova", 30, "Saler", 7500, 0.15, 0.15);
	employees[3] = new Employee("Max Fedotov", 35, "Accounter", 10500, 10, 20);
	for (int i = 0; i < N; i++)
	{
		cout << employees[i]->name << " salary = " << employees[i]->calcSalary() << endl;
	}
	for (int i = 0; i < N; i++)
	{
		delete employees[i];
	}
	delete[] employees;
	system("pause");
	return 0;
}
