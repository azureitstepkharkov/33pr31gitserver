#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include"HumanEntity.h"
#include<string>
#include<iostream>
using namespace std;
class Person: public HumanEntity 
{	

protected:
	string tel_num;
	AdressInfo* adr;
	Person() { cout << "call Person()" << endl; };
	Person(const Person& obj) { cout << "const Person& obj" << endl; };
	~Person() {};
public:
	Person(string teleph_num, AdressInfo* a) {
		this->tel_num = teleph_num;
		this->adr = a;
	}
	void setTel_num(string info_tel) { this->tel_num = info_tel; }
	void setAdr(AdressInfo* _adr) { this->adr = _adr; }
	string getTel_num() { return tel_num; }
	AdressInfo* getAge() { return adr; }
	friend ostream& operator << (ostream& out_data, Person& p)
	{
		out_data << "Telephone number is " << p.tel_num << endl;
		//out_data << "Age is" << a.age << endl;

		return out_data;
	};
};

