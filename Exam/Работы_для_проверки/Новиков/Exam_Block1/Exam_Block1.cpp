// Exam_Block1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AdressInfo.h"
#include "AnimalEntity.h"
#include "Person.h"
#include "HumanEntity.h"
#include "Department.h"
#include "Employee.h"
#include <iostream>
#include <string>

int main()
{
	Department d;
	d.pushBackEmployeeList("Bankir", "Bank card", 15000);
	cout << d << endl;
	return 0;
	system("pause");
    
}

