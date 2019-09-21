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
		out_data << "Город: " << info.get_city() << endl <<
			"Улица: " << info.get_outside() << endl <<
			"Дом: " << info.get_number_home() << endl <<
			"Квартира:" << info.get_number_KV() << endl <<
			"Пол: " << info.get_pol() << endl <<
			"Возраст: " << info.get_age() << endl <<
			"Имя: " << info.get_name() << endl <<
			"Фамилие: " << info.get_familie() << endl <<
			"Адрес: " << info.get_Adress() << endl <<
			"Номер телефона: " << info.get_Phone() << endl <<
			"Должность: " << info.get_position() << endl <<
			"Карточный счет: " << info.get_card_account() << endl <<
			"Зарплата: " << info.get_salary() << endl <<
			"Отдел: " << info.get_name_otdel() << endl <<
			"Сотрудник: " << info.get_sotrudnik() << endl <<
			"Начальник отдела: " << info.get_name_nachalnik_otdela() << endl;
		return out_data;
	};

	~Collection() {};
};

