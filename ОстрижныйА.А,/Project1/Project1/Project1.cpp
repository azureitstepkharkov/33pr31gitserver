// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"myfunctions.h"
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int sum = fnMySum(3, 7);
	cout << "sum =" << sum << endl;
    return 0;
	system("pause");
}

