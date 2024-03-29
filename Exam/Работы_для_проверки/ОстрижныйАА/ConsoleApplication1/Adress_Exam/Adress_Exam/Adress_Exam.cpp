// Adress_Exam.cpp : Defines the entry point for the console application.
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

class City
{
	string NameCity;
	City() { cout << "Attention Default Constructor City" << endl; }
	City(const City & obj) :NameCity(obj.NameCity) { cout << "Attention Copy Constructor City" << endl; }
public:
	City(string Name) { this->NameCity = Name; }
	void SetCity(string Name) { this->NameCity = Name; }
	string GetCity() { return NameCity; }

	/*friend ostream& operator<< (ostream& out_data, City& m)
	{
		out_data << "name City = " << m.NameCity << endl;
		return out_data;
	};*/
	friend class Adress;
	~City() {}
};

class TypeStreet
{
protected:
	string NameTypeStreet;
	TypeStreet() { cout << "Attention Default Constructor TypeStreet" << endl; }
	TypeStreet(const TypeStreet & obj) :NameTypeStreet(obj.NameTypeStreet) { cout << "Attention Copy Constructor TypeStreet" << endl; }
public:
	TypeStreet(string Name) { this->NameTypeStreet = Name; }
	void SetNameTypeStreet(string Name) { this->NameTypeStreet = Name; }
	string GetNameTypeStreet() { return NameTypeStreet; }

	/*friend ostream& operator<< (ostream& out_data, TypeStreet& m)
	{
		out_data << "name TypeStreet = " << m.NameTypeStreet << endl;
		return out_data;
	};*/


	friend class Street;
	~TypeStreet() {}
};

class Street :public  TypeStreet
{
private:
	string NameStreet;
	Street() { cout << "Attention Default Constructor Street" << endl; }
	Street(const Street & obj) :NameStreet(obj.NameStreet) { cout << "Attention Copy Constructor Street" << endl; }
public:
	Street(string Name) { this->NameStreet = Name; }
	void SetNameStreet(string Name) { this->NameStreet; }
	string GetNameStreet() { return NameStreet; }

	/*friend ostream& operator<< (ostream& out_data, TypeStreet& m)
	{
		out_data << "name Street = " << m.NameStreet << endl;
		return out_data;
	}*/

	friend class Adress;
	~Street() {}
};

class Adress 
{
private:
	City city;
	Street street;
	
	string NumHouse;
	int NumberFlat;

	Adress() { cout << "Attention Default Constructor Adres" << endl; }
	Adress(const Adress& obj) :city(obj.city), street(obj.street), NumHouse(obj.NumHouse), NumberFlat(obj.NumberFlat)
	{
		cout << "Attention Copy Constructor Adress" << endl;
	}


public:


	Adress(string city, string typestreet, string street, string numberhouse, int numberflat)
	{
		this->city = city;
		this->street.NameTypeStreet = typestreet;
		this->street.NameStreet = street;
		this->NumHouse = numberhouse;
		this->NumberFlat = numberflat;
		

	}

	friend ostream& operator<<(ostream& out_data, Adress& m)
	{
		out_data << "City " << m.city.GetCity() << endl <<
			"TypeStreet " << m.street.GetNameTypeStreet() << endl <<
			"Street " << m.street.GetNameStreet() << endl <<
			"NumberHouse " << m.GetNumHouse() << endl <<
			"NumberFlat " <<m.GetNumberFlat() <<endl ;

		return out_data;

	};

	void Setcity(City city) { this->city = city; }
	void SetTypeStreet(TypeStreet typestreet) { this->street.NameTypeStreet; }
	void Setstreet(Street street) { this->street = street; }
	void Setnumhouse(string numberhouse) { this->NumHouse = numberhouse; }
	void Setnumberflat(int nuvberflat) { this->NumberFlat = nuvberflat; }

	string GetCity() { return city.GetCity(); }
	string GetNumHouse() { return this->NumHouse; }
	string GetStreet() { return street.GetNameStreet(); }
	string GetTypeStreet() { return street.GetNameTypeStreet(); }
	int GetNumberFlat() { return this->NumberFlat; }



	~Adress() {}
};
// сортируемся по городу
bool operator < (Adress a, Adress b)
{
	return a.GetCity() < b.GetCity();
};
struct SortStreetType
{
	bool operator() (Adress& a, Adress &b)
	{
		return a.GetCity() < b.GetCity();
}
};

void Print(Adress a)
{
	cout << a;
}
bool MyGretta(Adress & el1, Adress & el2)
{
	return el1.GetCity() > el2.GetCity();
}
bool myComparergreaterOnAdress(Adress* a, Adress* b)
{
	return a->GetCity() < b->GetCity();
};


int main()
{
	setlocale(LC_ALL, "ru");

	vector <Adress*> Adr;
	Adress *A1 = new Adress("Kharkov", "Ulica", "Shevchenko", "155", 62);
	Adress *A2 = new Adress("Kiev", "Pereulok", "Petrova", "55", 16);
	Adress *A3 = new Adress("Piterburg", "Ulica", "Shevchenko", "7a", 22);
	Adress *A4 = new Adress("Kishenyev", "Ulica", "Shevchenko", "133", 33);
	Adress *A5 = new Adress("London", "Ulica", "Shevchenko", "12b", 45);
	Adr.push_back(A1);
	Adr.push_back(A2);
	Adr.push_back(A3);
	Adr.push_back(A4);
	Adr.push_back(A5);

	vector <Adress*>::iterator ptr;
	cout << endl << endl << "before sorting : " << endl;
	for (ptr = Adr.begin(); ptr < Adr.end(); ptr++)
		cout << *(*ptr) << " ";
	sort(Adr.begin(), Adr.end(), myComparergreaterOnAdress);
	cout << endl << endl << "after sorting :" << endl;
	for (ptr = Adr.begin(); ptr < Adr.end(); ptr++)
		cout << *(*ptr) << " ";

	// деструктор
	for (int i = 0; i < 5; i++)
	{
		delete Adr[i];
	}

	system("pause");
    return 0;
	
}

