#include "pch.h"
#include "AnimalEntity.h"



AnimalEntity::AnimalEntity()
{
}

AnimalEntity::AnimalEntity(char * gender_, int age_)
{
	gender = new char[strlen(gender_) + 1];
	strcpy_s(gender, strlen(gender_) + 1, gender_);
	delete[] gender_;

	if (age_ >= 0)
	{
		age = age_;
	}
	
}

void AnimalEntity::Set_Gender(char * gender_)
{
	gender = new char[strlen(gender_) + 1];
	strcpy_s(gender, strlen(gender_) + 1, gender_);
	delete[] gender_;
}

void AnimalEntity::Set_Age(int age_)
{
	if (age_ >= 0)
	{
		age = age_;
	}
}

char * AnimalEntity::Get_Gender()
{
	return gender;
}

int AnimalEntity::Get_Age()
{
	return age;
}


AnimalEntity::~AnimalEntity()
{
	delete[] gender;
}

ostream & operator<<(ostream & output, AnimalEntity & anmlent)
{
	output << "Gender:  " << anmlent.gender << endl;
	output << "Age is: " << anmlent.age << endl;
	return output;
}
