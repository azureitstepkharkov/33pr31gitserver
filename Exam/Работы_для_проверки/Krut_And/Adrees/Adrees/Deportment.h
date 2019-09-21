#pragma once
#include"AdressInfo.h"

class Deportment
{
protected:
	string name_otdel;
	string sotrudnik;
	string name_nachalnik_otdela;
public:
	Deportment() {};

	Deportment(string name_otdel, string sotrudnik, string name_nachalnik_otdela)
	{
		this->name_otdel = name_otdel;
		this->sotrudnik = sotrudnik;
		this->name_nachalnik_otdela = name_nachalnik_otdela;
	};

	void Print()
	{
		std::cout << "Отдел: " << name_otdel << endl <<
			"Сотрудник: " << sotrudnik << endl <<
			"Начальник отдела: " << name_nachalnik_otdela << endl;
	}


	string set_name_otdel(string name_otdel) { this->name_otdel = name_otdel; }
	string set_sotrudnik(string sotrudnik) { this->sotrudnik = sotrudnik; }
	string set_name_nachalnik_otdela(string name_nachalnik_otdela) { this->name_nachalnik_otdela = name_nachalnik_otdela; }

	string get_name_otdel() { return this->name_otdel; }
	string get_sotrudnik() { return this->sotrudnik; }
	string get_name_nachalnik_otdela() { return this->name_nachalnik_otdela; }

	friend ostream&  operator<< (ostream& out_data, Deportment& MEN)
	{
		out_data << "Отдел: " << MEN.get_name_otdel() << endl <<
			"Сотрудник: " << MEN.get_sotrudnik() << endl <<
			"Начальник отдела: " << MEN.get_name_nachalnik_otdela() << endl;
		return out_data;
	};

	~Deportment() {};
};