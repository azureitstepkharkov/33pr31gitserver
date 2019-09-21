#pragma once
#include"AdressInfo.h"
#include<string>
#include<iostream>	
#include <fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<list>
using namespace std;
class Person : public AdressInfo
{
private:
	string phoneNumber;

	Person() {};
	Person(const Person& obj) {}
public:

	void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }

	string getPhoneNumber() { return phoneNumber; }

	Person(string phoneNumber, string City, string Street, string HouseNumber, string OfficeOrApartmentNumber)
		:AdressInfo(City, Street, HouseNumber, OfficeOrApartmentNumber)
	{
		this->phoneNumber = phoneNumber;
	}

};