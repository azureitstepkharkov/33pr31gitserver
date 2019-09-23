#pragma once
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//������ �������
#include<functional>//������� ��� ���������� less<int> � �.�.
#include<string>//������ �� ��������
#include<list>//������ ������
using namespace std;


struct CalcInfo
{
	double base;//���� - �����
	double percent;//�������� %
	double total;//����� ������ ��� 
	double bonus;//�����
	double bonus_percent;//������� ������
	double hour;//���������� �����
	double rate_per_hour;//��������� ����
}info1;

struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};
//1 - �����
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

//2 - ������ �� �����
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

//3 - ������ � �������� //�������� ��� ������� �� �������
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

