#include "pch.h"

#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка
using namespace std;
//интерфейс - это struct или class  с секцией public, в которых
//только виртуальные методы
//
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};
//вместо всей иерархии струкутры: Animal->Man->Person
//здесь "заглушка" - только один класс
class Man
{
protected:
	Man(){}
	Man(const Man& onj){}
public:
	string name;//закрыть!
	//метода setName - не должно быть
	//string getName
	Man(string name) { this->name = name; }
};
//классы, которые хранят правила для рассчетов
//1 - оклад
class Rule1 : public ISalaryCalculator
{
protected:
	double base;
public:
	Rule1() { base = 0; }
	Rule1(double base) { this->base = base; }
	virtual double calcSalary()
	{
		return base;
	}
};
//2 - оплата по часам
class Rule2 : public ISalaryCalculator
{
protected:
	double hour;
	double rate;
public:
	Rule2() { hour = 0; rate = 0; }
	Rule2(double hour, double rate) { this->hour = hour; this->rate = rate; }
	virtual double calcSalary()
	{
		return hour * rate;
	}
};
//3 - оплата с бонусами
class Rule3 : public ISalaryCalculator
{
protected:
	double base;
	double percent;
	double bonus;
public:
	Rule3() { base = 0; percent = 0; bonus = 0; }
	Rule3(double base, double percent, double bonus)
	{
		this->base = base; this->percent = percent; this->bonus = bonus;
	}
	virtual double calcSalary()
	{
		return base + base * percent + bonus;
	}
};
//пример множественного наследования
class Employee : public Man, public ISalaryCalculator
{
protected:
	//составляющие части зп для расчета:
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или бонус
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
	//вопрос: а нужно ли их здесь вообще хранить?
	string position;//название должности
	ISalaryCalculator* salaryCalc;//механизм расчета ЗП
	//конструктор по умолчанию
	Employee() { salaryCalc = NULL; }
	//копирующий конструктор по умолчанию
	Employee(const Employee& obj) {}
public:
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}
	virtual ~Employee()
	{
		if (salaryCalc != NULL)
		{
			delete salaryCalc;
		}
	}
	//конструктор для должностей с оплатой по правилу 1
	Employee(string name, string position, double base)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->percent = 0;
		this->total = 0;
		this->salaryCalc = new Rule1(base);
	}
	//конструктор для должностей с оплатой по правилу 2
	Employee(string name, string position, double h, double rate)
		:Man(name)
	{
		this->position = position;
		this->hour = h;
		this->rate_per_hour = rate;
		this->percent = 0;
		this->total = 0;
		this->base = 0;
		this->salaryCalc = new Rule2(this->hour, this->rate_per_hour);
	}
	//конструктор для должностей с оплатой по правилу 3
	Employee(string name, string position, double base, double percent,double bonus)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->total = bonus;
		this->percent = percent;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->salaryCalc = new Rule3(base, percent, bonus);
	}
};
int main()
{
    std::cout << "test Employee:\n";
	const int N = 4;
	Employee** employes = new Employee*[N];
	employes[0] = new Employee("Ivan Petrov", "Accounter", 7500);
	employes[1] = new Employee("Peter Ivanov", "Programmer", 168, 6.25 * 25);
	employes[2] = new Employee("Anna Sidorova", "Senior Cleaner Manager", 80, 35);
	employes[3] = new Employee("BB", "Project Manager", 7500, 25, 10000);
	//вывод на экран
	for (int i = 0; i < N; i++)
	{
		cout << employes[i] << endl;
	}
	//удаление из памяти
	for (int i = 0; i < N; i++)
	{
		delete employes[i];
	}
	delete[] employes;
	system("pause");
	return 0;
}

