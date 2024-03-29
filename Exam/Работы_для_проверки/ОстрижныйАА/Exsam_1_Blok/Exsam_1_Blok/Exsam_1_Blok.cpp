// Exsam_1_Blok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;



	//////////////
	class Adress
	{
	private:
		string City;
		string Street;
		string NumHouse;
		int NumberFlat;

		Adress() { cout << "Attention Default Constructor Adres" << endl; }

		Adress(const Adress& obj) :City(obj.City), Street(obj.Street), NumHouse(obj.NumHouse), NumberFlat(obj.NumberFlat)
		{
			cout << "Attention Copy Constructor Adress" << endl;
		}


	public:


		Adress(string city, string street, string numberhouse, int numberflat)
		{
			this->City = city;
			this->Street = street;
			this->NumHouse = numberhouse;
			this->NumberFlat = numberflat;


		}

		friend ostream& operator<<(ostream& out_data, Adress& m)
		{
			out_data << "City " << m.city.GetCity() << endl <<
				"TypeStreet " << m.street.GetNameTypeStreet() << endl <<
				"Street " << m.street.GetNameStreet() << endl <<
				"NumberHouse " << m.GetNumHouse() << endl <<
				"NumberFlat " << m.GetNumberFlat() << endl;

			return out_data;

		};

		void Setcity(string city) { this->City = city; }
		void Setstreet(string street) { this->Street = street; }
		void Setnumhouse(string numberhouse) { this->NumHouse = numberhouse; }
		void Setnumberflat(int nuvberflat) { this->NumberFlat = nuvberflat; }

		string GetCity() { return this->City; }
		string GetNumHouse() { return this->NumHouse; }
		string GetStreet() { return this->Street; }
		int GetNumberFlat() { return this->NumberFlat; }



		~Adress() {}
	};


int main()
{
    return 0;
}

