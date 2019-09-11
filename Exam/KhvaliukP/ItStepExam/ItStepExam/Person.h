#pragma once
#include"AdressInfo.h"
class Person: public AdressInfo
{
private:
	char* phone;
	AdressInfo adress;
public:
	Person();
	Person(char* phone_);
	void Set_Phone(char* phone_);
	char* Get_Phone();
	~Person();
};

