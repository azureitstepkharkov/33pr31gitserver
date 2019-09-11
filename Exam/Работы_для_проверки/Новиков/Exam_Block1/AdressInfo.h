#pragma once
#include<string>
#include<iostream>
using namespace std;

class AdressInfo
{
private:
	string City;
	string Street;
	string HouseNumber;
	string OfficeOrApartmentNumber;
public:

	void setCity(string City)
	{
		this->City = City;
	}
	void setStreet(string Street)
	{
		this->Street = Street;
	}
	void setHouseNumber(string HouseNumber)
	{
		this->HouseNumber = HouseNumber;
	}
	void setOfficeOrApartmentNumber(string OfficeOrApartmentNumber)
	{
		this->OfficeOrApartmentNumber = OfficeOrApartmentNumber;
	}
	string getCity()
	{
		return City;
	}
	string getStreet()
	{
		return Street;
	}
	string getHouseNumber()
	{
		return HouseNumber;
	}
	string getOfficeOrApartmentNumber()
	{
		return OfficeOrApartmentNumber;
	}

	AdressInfo(string City, string Street, string HouseNumber, string OfficeOrApartmentNumber)
	{
		this->City = City;
		this->Street = Street;
		this->HouseNumber = HouseNumber;
		this->OfficeOrApartmentNumber = OfficeOrApartmentNumber;
	}

	void printAdress()
	{
		cout << "City = " << City << " ";
		cout << "Street = " << Street << " ";
		cout << "HouseNumber = " << HouseNumber << " ";
		cout << "OfficeOrApartmentNumber = " << OfficeOrApartmentNumber << endl;
	}

	friend ostream& operator<< (ostream& os, AdressInfo& data)
	{
		os << "City = " << data.City << " Street = " << data.Street << " HouseNumber = " << data.HouseNumber << " OfficeOrApartmentNumber = " << data.OfficeOrApartmentNumber << endl;
		return os;
	}

	AdressInfo() {}
	~AdressInfo() {};
};

