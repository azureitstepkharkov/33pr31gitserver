#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;



//////////////
class AdressInfo
{
protected:
	string City;
	string Street;
	string NumHouse;
	string NumberFlat;

	AdressInfo(const AdressInfo& obj) :City(obj.City), Street(obj.Street), NumHouse(obj.NumHouse), NumberFlat(obj.NumberFlat)
	{
		cout << "Attention Copy Constructor Adress" << endl;
	}
public:

	AdressInfo() { cout << "Attention Default Constructor Adres" << endl; }

	/*AdressInfo(const AdressInfo& obj) :City(obj.City), Street(obj.Street), NumHouse(obj.NumHouse), NumberFlat(obj.NumberFlat)
	{
		cout << "Attention Copy Constructor Adress" << endl;
	}*/





	AdressInfo(string city, string street, string numberhouse, string numberflat)
	{
		this->City = city;
		this->Street = street;
		this->NumHouse = numberhouse;
		this->NumberFlat = numberflat;


	}
	void Print()
	{
		std::cout << "City: " << City << endl <<
			 "Street: " << Street << endl <<
			"NumHouse: " << NumHouse << endl <<
			"NumberFlat: " << NumberFlat << endl;
	}

	//friend ostream& operator<<(ostream& out_data, AdressInfo& m)
	//{
	//	out_data << "City " << m.GetCity() << endl <<
	//		"Street " << m.GetStreet() << endl <<
	//		"NumberHouse " << m.GetNumHouse() << endl <<
	//		"NumberFlat " << m.GetNumberFlat() << endl;

	//	return out_data;

	//};

	void Setcity(string city) { this->City = city; }
	void Setstreet(string street) { this->Street = street; }
	void Setnumhouse(string numberhouse) { this->NumHouse = numberhouse; }
	void Setnumberflat(string nuvberflat) { this->NumberFlat = nuvberflat; }

	string GetCity() { return this->City; }
	string GetNumHouse() { return this->NumHouse; }
	string GetStreet() { return this->Street; }
	string GetNumberFlat() { return this->NumberFlat; }



	~AdressInfo() {}
};
#pragma once
