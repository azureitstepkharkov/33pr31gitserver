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
	list<AdressInfo*> adress;
public:

	void setPhoneNumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}

	void pushBackAdress(string phoneNumber, string City, string Street, string HouseNumber, string OfficeOrApartmentNumber)
	{
		AdressInfo* m = new AdressInfo(City, Street, HouseNumber, OfficeOrApartmentNumber);
		adress.push_back(m);
	}

	void printadress()
	{
		for_each(adress.begin(), adress.end(), printAdress);
	}

	string getPhoneNumber()
	{
		return phoneNumber;
	}

	friend ostream& operator<< (ostream& os, Person& data)
	{
		os << "phoneNumber = " << data.phoneNumber << " adress = " << data.printadress() << endl;
		return os;
	}

	Person() {};
	~Person() {};
};

