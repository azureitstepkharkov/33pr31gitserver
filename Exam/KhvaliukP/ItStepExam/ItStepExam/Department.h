#pragma once
#include<list>
#include<string>
#include <iterator>

using std::string;
using std::list;
class Department
{
private:
	char* department_name;
	list<string> employees_list;
public:
	Department();
	Department(char* department_name_);
	void Add_Item_Into_List(string item);
	void Set_DepartmentName(char* department_name_);
	char* Get_DepartmentName();
	string Get_Item_From_List();
	~Department();
};

