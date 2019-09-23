#pragma once
#include"Adress.h"
#include"Animal.h"
#include"Persona.h"
#include"HumanEntity.h"
#include"Employee.h"

class Reletion : public AdressInfo, public AnimalEntity, public HumanEntity, public Person, public Employee
{
public:
	Reletion() {};

	Reletion(string city, string street, string NumHouse, string numberflat, string Pol, string age, string name, string sname, /*string Adress,*/ string Phone, string position, string card_account, string salary)
	{
		this->City = city;
		this->Street = street;
		this->NumHouse = NumHouse;
		this->NumberFlat = numberflat;
		this->Pol = Pol;
		this->age = age;
		this->Name = name;
		this->Sname = sname;
		//this->Adress = Adress;
		this->Phone = Phone;
		this->position = position;
		this->card_account = card_account;
		this->salary = salary;
	};

	friend ostream& operator<< (ostream& out_data, Reletion& info)
	{
		out_data << "�����: " << info.GetCity() << endl <<
			"�����: " << info.GetStreet() << endl <<
			"���: " << info.GetNumHouse() << endl <<
			"��������:" << info.GetNumberFlat() << endl <<
			"���: " << info.get_pol() << endl <<
			"�������: " << info.get_age() << endl <<
			"���: " << info.get_name() << endl <<
			"�������: " << info.get_Sname() << endl <<
			/*"�����: " << info.get_Adress() << endl <<*/
			"����� ��������: " << info.get_Phone() << endl <<
			"���������: " << info.get_position() << endl <<
			"��������� ����: " << info.get_card_account() << endl <<
			"��������: " << info.get_salary() << endl;
		return out_data;
	};

	~Reletion() {};
};

