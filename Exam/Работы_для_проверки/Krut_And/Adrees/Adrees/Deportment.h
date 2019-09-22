#pragma once
#include"AdressInfo.h"
#include"Employee.h"

class Deportment
{
protected:
	string name_otdel;
	vector<Employee> sotrudniki;
	string name_nachalnik_otdela;
public:
	Deportment() {};

	Deportment(string name_otdel, string name_nachalnik_otdela)
	{
		this->name_otdel = name_otdel;
		this->name_nachalnik_otdela = name_nachalnik_otdela;
	};

	void Print()
	{
		std::cout << "Отдел: " << name_otdel << endl <<
			"Начальник отдела: " << name_nachalnik_otdela << endl;
	}

	void set_sotrudniki(Employee em) { this->sotrudniki.push_back(em); }

	string set_name_otdel(string name_otdel) { this->name_otdel = name_otdel; }
	string set_name_nachalnik_otdela(string name_nachalnik_otdela) { this->name_nachalnik_otdela = name_nachalnik_otdela; }

	string get_name_otdel() { return this->name_otdel; }
	string get_name_nachalnik_otdela() { return this->name_nachalnik_otdela; }

	void get_sotrudniki()
	{
		for (int i = 0; i < this->sotrudniki.size(); i++)
		{
			cout << sotrudniki[i];
		}
	}

	friend ostream&  operator<< (ostream& out_data, Deportment& MEN)
	{
		out_data << "Отдел: " << MEN.get_name_otdel() << endl <<
			"Начальник отдела: " << MEN.get_name_nachalnik_otdela() << endl;
		return out_data;
	};

	~Deportment() {};
};