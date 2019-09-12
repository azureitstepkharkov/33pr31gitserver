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
			"��������: " << info.get_salary() << endl;
		return out_data;
	};

	~Collection();
};

