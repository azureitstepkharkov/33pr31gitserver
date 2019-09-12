#pragma once
class HumanEntity
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

	~HumanEntity();
};

