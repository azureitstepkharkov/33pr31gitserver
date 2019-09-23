#pragma once
#include"AnimalEntity.h"
class HumanEntity: public AnimalEntity
{
private:
	char* name;
	char* surname;
public:
	HumanEntity();
	HumanEntity(char* name_, char* surname_);
	void Set_Name(char* name_);
	void Set_Surname(char* surname_);
	char* Get_Name();
	char* Get_Surname();
	friend ostream& operator << (ostream& output, HumanEntity& hmnentity);
	friend class Person;
	~HumanEntity();
};

