#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm> //������� ��������� ���������� ������
#include<vector> //����� ������������ ������, ������ int* paray = new int[N]
#include<functional> //����� ��������� ��������. ��� ��������� ����: greater<int>(), greater_equal<int>(), less_equal<int>()
#include<string> //����� ��� ������ �� ��������, ������ char*
#include<list> //����� ���� ����������� ������, ������ ���������������� ������ � ������ (��. ������ ListItem)

using namespace std;

class AdressInfo
{
protected:
	string city;
	string outside;
	string number_home;
	string number_KV;
public:
	AdressInfo() {};
	AdressInfo(string city, string outside, string number_home, string number_KV) 
	{
		//cout << "AdressInfo (string city, string outside, string number_home, string number_KV)" << endl;
		this->city = city;
		this->outside = outside;
		this->number_home = number_home;
		this->number_KV = number_KV;
	};

	void Print()
	{
		std::cout << "�����: " << city << endl <<
			"�����: " << outside << endl <<
			"���: " << number_home << endl <<
			"��������:" << number_KV << endl;
	}

	string set_city(string city) { this->city = city; }
	string set_outside(string outside) { this->outside = outside; }
	string set_number_home(string number_home) { this->number_home = number_home; }
	string set_number_KV(string number_KV) { this->number_KV = number_KV; }

	string get_city() { return this->city; }
	string get_outside() { return this->outside; }
	string get_number_home() { return this->number_home; }
	string get_number_KV() { return this->number_KV; }

	~AdressInfo() {};
};

