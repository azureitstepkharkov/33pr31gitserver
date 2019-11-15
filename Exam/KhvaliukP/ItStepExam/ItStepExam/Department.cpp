#include "pch.h"
#include "Department.h"


Department::Department()
{
}

Department::Department(char * department_name_, char * director_, Empoyee * emloyer_)
{
	department_name = new char[strlen(department_name_) + 1];
	strcpy_s(department_name, strlen(department_name_) + 1, department_name_);
	delete[] department_name_;

	director = new char[strlen(director_) + 1];
	strcpy_s(director, strlen(director_) + 1, director_);
	delete[] director_;

	this->employer = emloyer_;
}


//
//Department::Department(char * department_name_)
//{
//	department_name = new char[strlen(department_name_) + 1];
//	strcpy_s(department_name, strlen(department_name_) + 1, department_name_);
//	delete[] department_name_;
//}
//
//void Department::Add_Item_Into_List(string item)
//{
//	employees_list.push_back(item);
//}
//
//void Department::Set_DepartmentName(char * department_name_)
//{
//	department_name = new char[strlen(department_name_) + 1];
//	strcpy_s(department_name, strlen(department_name_) + 1, department_name_);
//	delete[] department_name_;
//}
//
//char * Department::Get_DepartmentName()
//{
//	return department_name;
//}
/*
string Department::Get_Items_From_List()
{
	return string();
}

*/
Department::~Department()
{
}
