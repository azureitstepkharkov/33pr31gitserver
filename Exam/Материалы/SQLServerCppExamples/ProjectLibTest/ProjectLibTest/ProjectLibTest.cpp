// ProjectLibTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"myfunctionsh.h"
#include<Windows.h>
#include<iostream>
#include<string>
#pragma comment(lib,"Project09.09.2019.lib")
using namespace std;
int main()
{
	cout << "Hello,World!" << endl;
	int sum = fnMySum(3, 7);
	cout << "sum = " << sum << endl;
	system("pause");
    return 0;
}

