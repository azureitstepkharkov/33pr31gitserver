#include "pch.h"
#include "HumanEntity.h"


HumanEntity::HumanEntity()
{
}

HumanEntity::HumanEntity(char * name_, char * surname_)
{
	name = new char[strlen(name_) + 1];
	strcpy_s(name, strlen(name_) + 1, name_);
	delete[] name_;

	surname = new char[strlen(surname_) + 1];
	strcpy_s(surname, strlen(surname_) + 1, surname_);
	delete[] surname_;
}

void HumanEntity::Set_Name(char * name_)
{
	name = new char[strlen(name_) + 1];
	strcpy_s(name, strlen(name_) + 1, name_);
	delete[] name_;
}

void HumanEntity::Set_Surname(char * surname_)
{
	surname = new char[strlen(surname_) + 1];
	strcpy_s(surname, strlen(surname_) + 1, surname_);
	delete[] surname_;
}

char * HumanEntity::Get_Name()
{
	return name;
}

char * HumanEntity::Get_Surname()
{
	return surname;
}


HumanEntity::~HumanEntity()
{
	delete[] name;
	delete[] surname;
}

ostream & operator<<(ostream & output, HumanEntity & hmnentity)
{
	output << "Name: " << hmnentity.name << endl;
	output << "Surname: " << hmnentity.surname << endl;
	return output;
}
