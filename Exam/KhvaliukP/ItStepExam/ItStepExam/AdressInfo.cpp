#include "pch.h"
#include "AdressInfo.h"



AdressInfo::AdressInfo()
{
}

AdressInfo::AdressInfo(char * city_, char * street_, char * building_number_, char * apartment_number_)
{
	city = new char[strlen(city_) + 1];
	strcpy_s(city, strlen(city_) + 1, city_);
	delete[] city_;

	street = new char[strlen(street_) + 1];
	strcpy_s(street, strlen(street_) + 1, street_);
	delete[] street_;

	building_number = new char[strlen(building_number_) + 1];
	strcpy_s(building_number, strlen(building_number_) + 1, building_number_);
	delete[] building_number_;

	apartment_number = new char[strlen(apartment_number_) + 1];
	strcpy_s(apartment_number, strlen(apartment_number_) + 1, apartment_number_);
	delete[] apartment_number_;
}

void AdressInfo::Set_City(char * city_)
{
	city = new char[strlen(city_) + 1];
	strcpy_s(city, strlen(city_) + 1, city_);
	delete[] city_;
}

void AdressInfo::Set_Street(char * street_)
{
	street = new char[strlen(street_) + 1];
	strcpy_s(street, strlen(street_) + 1, street_);
	delete[] street_;
}

void AdressInfo::Set_BuildingNumber(char * building_number_)
{
	building_number = new char[strlen(building_number_) + 1];
	strcpy_s(building_number, strlen(building_number_) + 1, building_number_);
	delete[] building_number_;
}

void AdressInfo::Set_AppartmentNumber(char * apartment_number_)
{
	apartment_number = new char[strlen(apartment_number_) + 1];
	strcpy_s(apartment_number, strlen(apartment_number_) + 1, apartment_number_);
	delete[] apartment_number_;
}

char * AdressInfo::Get_City()
{
	return city;
}

char * AdressInfo::Get_Street()
{
	return street;
}

char * AdressInfo::Get_BuildingNumber()
{
	return building_number;
}

char * AdressInfo::Get_ApartmentNumber()
{
	return apartment_number;
}


AdressInfo::~AdressInfo()
{
	delete[] city;
	delete[] street;
	delete[] building_number;
	delete[] apartment_number;
}
