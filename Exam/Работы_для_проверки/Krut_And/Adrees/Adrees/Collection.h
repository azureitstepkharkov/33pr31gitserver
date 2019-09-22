#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include"Person.h"
#include"HumanEntity.h"
#include"Employee.h"
#include"Deportment.h"

class Collection : public AdressInfo, public AnimalEntity, public HumanEntity, public Person, public Employee, public Deportment
{
public:
	Collection() {};

	Collection(string city, string outside, string number_home, string number_KV, string Pol, string age, string name, string familie, string Adress, string Phone, string position, string card_account, string salary, string name_otdel, string sotrudnik, string name_nachalnik_otdela)
	{
		this->city = city;
		this->outside = outside;
		this->number_home = number_home;
		this->number_KV = number_KV;
		this->Pol = Pol;
		this->age = age;
		this->name = name;
		this->familie = familie;
		this->Adress = Adress;
		this->Phone = Phone;
		this->position = position;
		this->card_account = card_account;
		this->salary = salary;
		this->name_otdel = name_otdel;
		this->sotrudnik = sotrudnik;
		this->name_nachalnik_otdela = name_nachalnik_otdela;
	};

	friend ostream&  operator<< (ostream& out_data, Collection& info)
	{
		out_data << "�����: " << info.get_city() << endl <<
			"�����: " << info.get_outside() << endl <<
			"���: " << info.get_number_home() << endl <<
			"��������:" << info.get_number_KV() << endl <<
			"���: " << info.get_pol() << endl <<
			"�������: " << info.get_age() << endl <<
			"���: " << info.get_name() << endl <<
			"�������: " << info.get_familie() << endl <<
			"�����: " << info.get_Adress() << endl <<
			"����� ��������: " << info.get_Phone() << endl <<
			"���������: " << info.get_position() << endl <<
			"��������� ����: " << info.get_card_account() << endl <<
			"��������: " << info.get_salary() << endl <<
			"�����: " << info.get_name_otdel() << endl <<
			"���������: " << info.get_sotrudnik() << endl <<
			"��������� ������: " << info.get_name_nachalnik_otdela() << endl;
		return out_data;
	};

	~Collection() {};
};

