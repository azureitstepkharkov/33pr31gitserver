// Exam_Shevchenko_33PR31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
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
public:
AdressInfo(AdressInfo& adr) {
	this->City = adr.City;
	this->TypeStreet = adr.TypeStreet;
	this->Street = adr.Street;
	this->HouseHumber = adr.HouseHumber;
	this->OfficeOrApartmentNum = adr.OfficeOrApartmentNum;
};
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


class Employee: public Person, public AdressInfo
{
protected:
	string Position;
	string BankAccount;
	string Salary;
	Employee() {};
	
public:
	/*Employee(Employee& emp) {
		this->Position = emp.Position;
		this->BankAccount = emp.BankAccount;
		this->Salary = emp.Salary;
		this->phone = emp.phone;
		this->sex = emp.sex;
		this->age = emp.age;
		this->Name = emp.Name;
		this->Surname = emp.Surname;
		this->City = emp.City;
		this->TypeStreet = emp.TypeStreet;
		this->Street = emp.Street;
		this->HouseHumber = emp.HouseHumber;
		this->OfficeOrApartmentNum = emp.OfficeOrApartmentNum;
		
	};*/
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
		out_data <<data.Name << " "<< data.Surname << " " << data.phone << " " <<
			data.adress->get_city() << " " << data.adress->get_typestreet() << " " <<
			data.adress->get_street() << " " << data.adress->get_housenum() << " "
			<< data.adress->get_apartmentnum() << " " << data.get_sex()
			<< " " << data.get_age() << data.Position << " " << data.BankAccount <<
			" " << data.Salary << " " << endl;
		return out_data;
	}

	~Employee() {};
};



class Department
{
protected:
	string DepartmentName;
	vector<Employee>employees;
	HumanEntity* Cheif;
	Department() {};
	Department(Department& dep) {};
public:
	Department(string depname, string name, string surname, string sex,
		unsigned int age)
	{
		this->DepartmentName = depname;
		this->Cheif = new HumanEntity(name, surname, sex, age);
	};
	friend ostream& operator<<(ostream& out_data, Department& data)
	{
		out_data << data.DepartmentName   << " " << data.Cheif
			<< endl;
		return out_data;
	}
	void set_Employee(Employee a) {
		this->employees.push_back(a);
	}
	void get_Employees()
	{
		for (int i = 0; i < this->employees.size(); i++)
		{
			cout << employees[i];
		}
	}
	~Department() {};
};

//////////////////////////////
//////////////////////////////
//–асчет зарплаты////////////
///////////////////////////
////////////////////////////

struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};


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
	double total;
public:
	Rule3() { base = 0; percent = 0; total = 0; }
	Rule3(double base, double percent, double total)
	{
		this->base = base; this->percent = percent; this->total = total;
	}
	virtual double calcSalary()
	{
		return base + total * percent;
	}
};
//оклад + преми€
class Rule4 : public ISalaryCalculator
{
protected:
	double salary;
	double bonus;
public:

	Rule4() { this->salary = 0; this->bonus = 0; }
	Rule4(double salary, double bonus)
	{
		this->salary = salary; this->bonus = bonus;
	}
	virtual double calcSalary()
	{
		return salary + bonus;
	}
};
//все данные, которые могут понадобитьс€ дл€ расчета «ѕ
struct CalcInfo
{
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или 
	double bonus;//бонус
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
};

class EmployeeSalary : public HumanEntity, public ISalaryCalculator
{
protected:
	
	double base;
	double percent;
	double total;
	double hour;
	double rate_per_hour;
	string position;
	ISalaryCalculator* salaryCalc;
	
public:
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}

	EmployeeSalary(string name,string surname,string sex, unsigned int age,
		string position, int codePosition, CalcInfo info)
		:HumanEntity(name, surname, sex, age)
	{
		this->position = position;
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

	friend ostream& operator<< (ostream& os, EmployeeSalary& data)
	{
		os << "name = " << data.Name <<" Suraname = " << data.Surname<< " sex = " << data.sex
			<< " age = " << data.age << " position = " << data.position
			<< " salary = " << data.calcSalary() << endl;
		return os;
	}
	//
};


int main()
{
   cout << "My Exam!!!\n"; 

   //Person a("+380994597228", "Kharkov", "street", "Sumskaya", "45a", 84, "Aleksandr", "Petrov", "male", 23);

   Employee b("Programmer", "5168755434678912", "20000", "0994567132", "Kharkov", "prospect",
	   "Moskovskiy", "248a", 47, "Andrey", "Ivanov", "man", 25);
   Employee c("Sailer", "5168755434934729", "18000", "0994593456", "Kharkov", "street", "Sumskaya", 
	   "47", 6, "Mark", "Petrenko", "man", 33);
   Employee d("Cleaner", "5168755434834502", "10000", "0994560941", "Kharkov", "prospect", 
	   "Moskovskiy", "24", 30, "Anna", "Ivanova", "woman", 65);

   //я старалась, но € запуталась и хочу спать... =(

   vector<Department>departments(50);
   int n = departments.size();
   Department aDep("Saleers", "Viktor", "Baranov", "man", 44);
   Department bDep("It", "Maxim", "Aleksandrov", "man", 34);
   departments.push_back(aDep);
   departments.push_back(bDep);
  
   aDep.set_Employee(b);
   aDep.set_Employee(c);
   aDep.set_Employee(d);

   aDep.get_Employees();

   ///////////////////////////////////////////
   //salary/////////////////////////
   ///////////////////////////////////

   const int N = 5;
   EmployeeSalary** employes = new EmployeeSalary*[N];

   CalcInfo info;
   info.base = 7500;
   info.percent = 15;
   info.total = 100000;
   employes[0] = new EmployeeSalary("Alex", "Alex","man", 26, "Saler", 4, info);

   for (int i = 0; i < N; i++)
   {
	   cout << *employes[i] << endl;
   }

   for (int i = 0; i < N; i++)
   {
	   delete employes[i];
   }
   delete[] employes;
  
   
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
