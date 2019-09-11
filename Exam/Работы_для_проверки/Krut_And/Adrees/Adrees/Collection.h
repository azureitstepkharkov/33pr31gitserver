#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include"Person.h"
#include"HumanEntity.h"
#include"Employee.h"

class Collection : public AdressInfo, public AnimalEntity, public HumanEntity, public Person, public Employee
{
public:
	Collection();

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
			"Зарплата: " << info.get_salary() << endl;
		return out_data;
	};

	~Collection();
};

