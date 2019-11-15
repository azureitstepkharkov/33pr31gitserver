#pragma once
#include<list>
#include<string>
#include <iterator>
#include"Empoyee.h"
using namespace std;
using std::string;
using std::list;
class Department
{
private:
	char* department_name;
	char* director;
	Empoyee *employer;
	//list<string> employees_list;
public:
	Department();
	Department(char * department_name_, char * director_, Empoyee *emloyer_);
	//Department(char* department_name_);
	//void Add_Item_Into_List(string item);
	//void Set_DepartmentName(char* department_name_);
	//char* Get_DepartmentName();
	//string Get_Item_From_List();
	~Department();
};

