#pragma once
#include "stdafx.h"
#include "AdressInfo.h"
#include "AnimalEntity.h"
#include "Person.h"
#include "HumanEntity.h"
#include "Department.h"
#include "Employee.h"
#include"MyList.h"

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
	/*MyList<int> list;
	list.pusBack(1);
	list.pusBack(2);
	list.pusBack(3);
	list.pusBack(4);
	list.pusBack(5);
	list.Print();
	cout << endl;
	list.revercePrint();
	cout << endl;
	cout << list.getSize();
	cout << endl;
	cout << list[2];*/

	MyList<Department*> d;

	Department* d1 = new Department("DepartmentName1", "DepartmentDirector1", "position1", "BankCardAccount1", 10000);
	Department* d2 = new Department("DepartmentName2", "DepartmentDirector2", "position2", "BankCardAccount2", 20000);
	Department* d3 = new Department("DepartmentName3", "DepartmentDirector3", "position3", "BankCardAccount3", 30000);
	Department* d4 = new Department("DepartmentName4", "DepartmentDirector4", "position4", "BankCardAccount4", 40000);
	Department* d5 = new Department("DepartmentName5", "DepartmentDirector5", "position5", "BankCardAccount5", 50000);

	d.pusBack(d1);
	d.pusBack(d2);
	d.pusBack(d3);
	d.pusBack(d4);
	d.pusBack(d5);

	for (int i = 0; i < d.getSize(); i++)
	{
		d[i]->Print();
		cout << endl;
	}

	return 0;
	system("pause");
}