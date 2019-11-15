#pragma once
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка
using namespace std;


struct CalcInfo
{
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или 
	double bonus;//бонус
	double bonus_percent;//процент бонуса
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
}info1;

struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};
//1 - оклад
class Rule1 : public ISalaryCalculator
{
protected:
	/*double base;*/
public:
	Rule1() { info1.base = 0; }
	Rule1(double base) { info1.base = base; }
	virtual double calcSalary()
	{
		return info1.base;
	}
};

//2 - оплата по часам
class Rule2 : public ISalaryCalculator
{
protected:
	/*double hour;
	double rate;*/
public:
	Rule2() { info1.hour = 0; info1.rate_per_hour = 0; }
	Rule2(double hour, double rate) {info1.hour = hour; info1.rate_per_hour = rate; }
	virtual double calcSalary()
	{
		return info1.hour * info1.rate_per_hour;
	}
};

//3 - оплата с бонусами //изменить под процент от выручки
class Rule3 : public ISalaryCalculator
{
protected:
	/*double base;
	double percent;
	double bonus;*/
public:
	Rule3() { info1.base = 0; info1.percent = 0; info1.bonus = 0; }
	Rule3(double base, double percent, double bonus)
	{
		info1.base = base; info1.percent = percent; info1.bonus = bonus;
	}
	virtual double calcSalary()
	{
		return info1.base + info1.base * info1.percent + info1.bonus;
	}
};

