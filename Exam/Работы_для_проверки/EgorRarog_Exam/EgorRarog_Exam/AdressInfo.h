#pragma once
#include <iostream>
#include<string>

using namespace std;
class AdressInfo
{
protected:
	string City;
	string Street;
	string num_of_house;
	string num_of_flat;
	AdressInfo() { cout << "call AdressInfo()" << endl; };
	AdressInfo(const AdressInfo& obj) { cout << "const AdressInfo& obj" << endl; };
	~AdressInfo() {};
public:
	AdressInfo(string CityName, string Street_name, string num_house, string num_flat) {
		this->City = CityName;
		this->num_of_flat = num_flat;
		this->num_of_house = num_house;
		this->Street = Street_name;
	}
	void setCity(string name) { this->City = name; }
	void setStreet(string name) { this->Street = name; }
	void setNumOfFlat(string name) { this->num_of_flat = name; }
	void setNumOfHouse(string name) { this->num_of_house = name; }
	string getCity() { return City; }
	string getStreet() { return Street; }
	string getNumOfFlat() { return num_of_flat; }
	string getNumOHouse() { return num_of_house; }

	friend ostream& operator << (ostream& out_data, AdressInfo& a)
	{
		out_data << "City is " << a.City << endl;
		out_data << "Street is " << a.Street << endl;
		out_data << "Number of house is " << a.num_of_house << endl;
		out_data << "Number of flat is " << a.num_of_flat << endl;
		return out_data;
	};

	friend class AnimalEntity;
};
