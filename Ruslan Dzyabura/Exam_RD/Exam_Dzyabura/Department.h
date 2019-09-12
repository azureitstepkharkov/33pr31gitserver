#pragma once
#include"AdressInfo.h"
#include"AnimalEntity.h"
#include"HumanEntity.h"
#include"Person.h"
#include"Employee.h"
#include<string>
#include<list>
#include<iostream>
using namespace std;
class Department : public Employee
{	 
	string group_name;
	string director;
	Employee *employer;
	Department() {};
	~Department() {};
public:
	Department(string gr_name,string dir,Employee *empl) {
		this->director = dir;
		this->group_name = gr_name;
		this->employer = empl;
	};

};

