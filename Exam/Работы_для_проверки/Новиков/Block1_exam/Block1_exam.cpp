// Block1_exam.cpp : Defines the entry point for the console application.
//

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


	MyList<Department*> d;

	Department* d1 = new Department("DepName1", "DepDirector1", "position1", "BankAccount1", 404);
	Department* d2 = new Department("DepName2", "DepDirector2", "position2", "BankAccount2", 444);
	Department* d3 = new Department("DepName3", "DepDirector3", "position3", "BankAccount3", 30003);
	Department* d4 = new Department("DepName4", "DepDirector4", "position4", "BankAccount4", 4);
	Department* d5 = new Department("DepName5", "DepDirector5", "position5", "BankAccount5", 4444);

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

	return 0;
	system("pause");
}