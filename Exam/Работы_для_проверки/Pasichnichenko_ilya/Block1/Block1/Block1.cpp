#pragma once
#include "stdafx.h"
#include "AdressInfo.h"
#include "AnimalEntity.h"
#include "Person.h"
#include "HumanEntity.h"
#include "Department.h"
#include "Employee.h"

#include <iostream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>

using namespace std;

int main()
{

	Department d;
	d.pushBackEmployeeList("programmer", "number card", 20000);//string position, string BankCardAccount, double salary
	cout << d << endl;
    return 0;
	system("pause");
}

