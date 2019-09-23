#pragma once
#include<iostream>
using namespace std;
class AdressInfo
{
protected:
	char* city;
	char* street;
	char* building_number;
	char* apartment_number;
	

public:
	AdressInfo();
	AdressInfo(char* city_, char* street_, char* building_number_, char* apartment_number_);
	void Set_City(char* city_);
	void Set_Street(char* street_);
	void Set_BuildingNumber(char* building_number_);
	void Set_AppartmentNumber(char* apartment_number_);
	char* Get_City();
	char* Get_Street();
	char* Get_BuildingNumber();
	char* Get_ApartmentNumber();
		AdressInfo(AdressInfo& adressinfo) {};
	~AdressInfo();
	friend ostream& operator << (ostream& output, AdressInfo& adress);

	friend class AnimalEntity;
};

