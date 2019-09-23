#pragma once
#include<string>
#include<iostream>
using namespace std;

class AdressInfo
{
protected:
	string City;
	string Street;
	string HouseNumber;
	string OfficeOrApartmentNumber;

	AdressInfo() {}
	AdressInfo(const AdressInfo& obj) {}
public:

	void setCity(string City){this->City = City;}
	void setStreet(string Street){this->Street = Street;}
	void setHouseNumber(string HouseNumber){this->HouseNumber = HouseNumber;}
	void setOfficeOrApartmentNumber(string OfficeOrApartmentNumber){this->OfficeOrApartmentNumber = OfficeOrApartmentNumber;}

	string getCity(){return City;}
	string getStreet(){return Street;}
	string getHouseNumber(){return HouseNumber;}
	string getOfficeOrApartmentNumber(){return OfficeOrApartmentNumber;}

	AdressInfo(string City, string Street, string HouseNumber, string OfficeOrApartmentNumber)
	{
		this->City = City;
		this->Street = Street;
		this->HouseNumber = HouseNumber;
		this->OfficeOrApartmentNumber = OfficeOrApartmentNumber;
	}
};