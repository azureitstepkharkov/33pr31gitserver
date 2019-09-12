#include "pch.h"
#include <iostream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;

class City
{
private:
	string nameCity;
	City() {}
	City(const City& obj) :nameCity(obj.nameCity) { cout << "VORNING COPIROVANIE" << endl; }
public:



	City(string name) {
		this->nameCity = name;
	}
	void setCity(string name) { this->nameCity = name; }
	string getCity() { return nameCity; }
	friend ostream& operator << (ostream& out_data, City& m)
	{
		out_data << "name = " << m.nameCity << endl;

		return out_data;
	};
	friend class Adress;
	~City() { cout << "USING" << endl; }
};

class TypeStreet
{
protected:
	string Typename;
	TypeStreet() {}
	TypeStreet(const TypeStreet& obj) :Typename(obj.Typename) { cout << "VORNING COPIROVANIE" << endl; }
public:
	~TypeStreet() { cout << "USING" << endl; }


	TypeStreet(string name) { this->Typename = name; }

	void setTypeStreet(string name) { this->Typename = name; }
	string geеtTypeStreet() { return Typename; }
	friend ostream& operator << (ostream& out_data, TypeStreet& m)
	{
		out_data << "name = " << m.Typename << endl;
		return out_data;
	};

	friend class Street;
};

class Street :public TypeStreet
{
private:
	string nameStreet;

	Street() {}
	Street(const Street& obj, const TypeStreet& nameType) :nameStreet(obj.nameStreet) {
		cout << "VORNING COPIROVANIE" << endl;
	}
public:



	~Street() { cout << "USING" << endl; }
	Street(string name, string TypeStreet) :TypeStreet(TypeStreet) {
		this->nameStreet = name;
		this->Typename = TypeStreet;
	}
	void setStreet(string name) { this->nameStreet = name; }
	string geеtStreet() { return nameStreet; }
	friend ostream& operator << (ostream& out_data, Street& m)
	{
		out_data << "nameStreet = " << m.nameStreet << endl << "TypStreet = " << m.Typename << endl;
		return out_data;
	};

	friend class Adress;
};
class Adress
{
private:
	City city;
	Street street;
	string NumHouse;
	Adress() {}
	Adress(const Adress& obj) :city(obj.city), street(obj.street), NumHouse(obj.NumHouse)
	{
		cout << "VORNING COPIROVANIE" << endl;
	}

public:


	friend ostream& operator << (ostream& out_data, Adress& m)
	{
		out_data << "City " << m.city.getCity() << endl << "TypStreet " << m.street.geеtTypeStreet() << endl << "name " << m.street.geеtStreet() << endl << "NumHouse " << m.get_NumHouse() << endl;
		return out_data;
	};
	~Adress() { cout << "USING " << endl; }
	Adress(string sity, string street, string NumHouse, string TypeStreet)
	{
		this->street.nameStreet = street;
		this->street.Typename = TypeStreet;
		this->city = sity;
		this->NumHouse = NumHouse;

	}


	void set_city(City city)
	{
		this->city = city;
	}
	void set_street(Street street)
	{
		this->street = street;
	}
	void set_NumHouse(string NumHouse)
	{
		this->NumHouse = NumHouse;
	}
	string get_NumHouse()
	{
		return this->NumHouse;
	}

	string get_City()
	{
		return city.getCity();
	}
	string  get_Street()
	{
		return street.geеtStreet();
	}
	string get_StreetType()
	{
		return street.geеtTypeStreet();
	}



};

//struct AdressSort
//{
//	bool operator()(Adress& a, Adress& b) {
//		
//		return a.get_NumHouse()< b.get_NumHouse();
//	}
//};
//
//
//void Print(Adress a)
//{
//	cout << a;
//}
//bool operator < (Adress m, Adress b)
//{
//	return m.get_NumHouse() < b.get_NumHouse();
//};

//bool operator < (Adress& m, Adress &b)
//{
//	return m.get_StreetType() < b.get_StreetType();
//};
//
//struct SortStreetType
//{
//	bool operator() (Adress& a, Adress &b)
//	{
//		return a.get_StreetType() < b.get_StreetType();
//	}
//
//
//};

bool operator < (Adress m, Adress b)
{
	return m.get_NumHouse() < b.get_NumHouse();
};

struct SortStreetType
{
	bool operator() (Adress& a, Adress &b)
	{
		return a.get_NumHouse() < b.get_NumHouse();
	}


};
void Print(Adress a)
{
	cout << a;
}



//bool operator < (Adress m, Adress b)
//{
//		return m.get_City() < b.get_City();
//};
//
//struct SortCity
//{
//	bool operator() (Adress& a, Adress &b)
//	{
//		return a.get_City() < b.get_City();
//	}
//
//
//};

bool MyGretta(Adress & el1, Adress & el2)
{
	return el1.get_NumHouse() > el2.get_NumHouse();

}
bool mycomparergreater(Adress *a, Adress * b)
{
	return a->get_City() < b->get_City();

}

void printAdress(Adress *a)
{
	cout << *a;

}



int main()
{
	Adress a("London", "Pushkina", "12D", "Pereuloc");
	Adress b("Parish", "Shevchenco", "11D", "ULICA");
	Adress c("Kiev", "Gagarina", "10", "Spusc");
	Adress d("Moscov", "Chehova", "12N", "ULICA");
	Adress i("Berlin", "Pobeda", "14", "street");

	/*vector<Adress> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	sort(v.begin(), v.end(), less<Adress>());
	for_each(v.begin(), v.end(), Print);*/

	/*sort(v.begin(), v.end(), MyGretta);
	cout << endl<< endl;
	for_each(v.begin(), v.end(), Print);

	list<Adress> ListAdress({ a });
	ListAdress.push_front(b);
	ListAdress.push_front(c);
	ListAdress.push_front(d);
	ListAdress.push_front(i);
	for_each(ListAdress.begin(), ListAdress.end(), Print);
	ListAdress.sort();
	cout << endl << endl;
	for_each(ListAdress.begin(), ListAdress.end(), Print);
	ListAdress.sort(MyGretta);
	cout << endl << endl;
	for_each(ListAdress.begin(), ListAdress.end(), Print);
	*/

	vector<Adress *> Vadres;
	Adress* A1 = new Adress("London", "Pushkina", "12D", "Pereuloc");
	Adress* A2 = new Adress("Parish", "Shevchenco", "11D", "ULICA");
	Adress *A3 = new Adress("Kiev", "Gagarina", "10", "Spusc");
	Adress *A4 = new Adress("Moscov", "Chehova", "12N", "ULICA");
	Adress *A5 = new Adress("Berlin", "Pobeda", "14", "street");
	Vadres.push_back(A1);
	Vadres.push_back(A2);
	Vadres.push_back(A3);
	Vadres.push_back(A4);
	Vadres.push_back(A5);
	list<Adress*> ListAdress({ A1 });
	ListAdress.push_front(A2);
	ListAdress.push_front(A3);
	ListAdress.push_front(A4);
	ListAdress.push_front(A5);
	for_each(ListAdress.begin(), ListAdress.end(), printAdress);
	ListAdress.sort(mycomparergreater);
	cout << endl << endl;
	for_each(ListAdress.begin(), ListAdress.end(), printAdress);
	//vector<Adress*>::iterator ptr;
	//for (ptr = Vadres.begin();ptr < Vadres.end(); ptr++)
	//	cout << *(*ptr) << " ";

	//sort(Vadres.begin(), Vadres.end(), mycomparergreater);
	//cout << endl << endl;
	//for (ptr = Vadres.begin();ptr < Vadres.end(); ptr++)
	//	cout << *(*ptr) << " ";
	//	
	//for (int i = 0;i < 5;i++)
	//{
	//	Vadres[i]->~Adress();
	//	
	//}

	/*ListAdress.sort();
	cout << endl << endl;
	for_each(ListAdress.begin(), ListAdress.end(), Print);
	ListAdress.sort(MyGretta);
	cout << endl << endl;
	for_each(ListAdress.begin(), ListAdress.end(), Print);*/


	system("pause");
}

