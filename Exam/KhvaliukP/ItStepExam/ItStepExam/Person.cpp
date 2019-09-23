#include "pch.h"
#include "Person.h"


Person::Person()
{
}

Person::Person(char * phone_)
{
	phone = new char[strlen(phone_) + 1];
	strcpy_s(phone, strlen(phone_) + 1, phone_);
	delete[] phone_;
}

void Person::Set_Phone(char * phone_)
{
	phone = new char[strlen(phone_) + 1];
	strcpy_s(phone, strlen(phone_) + 1, phone_);
	delete[] phone_;
}

char * Person::Get_Phone()
{
	return phone;
}


Person::~Person()
{
	delete[] phone;
}

ostream & operator<<(ostream & output, Person & prsn)
{
	output << "Phone num.: " << prsn.phone << endl;
	return output;
}
