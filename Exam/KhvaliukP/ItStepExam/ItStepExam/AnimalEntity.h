#pragma once
#include<iostream>
#include"AdressInfo.h"
using namespace std;
class AnimalEntity
{
private:
	char* gender;
	int age;
public:
	AnimalEntity();
	AnimalEntity(char* gender_, int age);
	void Set_Gender(char* gender_);
	void Set_Age(int age_);
	char* Get_Gender();
	int Get_Age();
	friend ostream& operator << (ostream& output, AnimalEntity& anmlent);
	friend class HumanEntity;
	~AnimalEntity();
};

