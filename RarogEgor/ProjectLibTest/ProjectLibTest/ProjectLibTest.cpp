// ProjectLibTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"myfuctions.h"
#include<Windows.h>
#include <iostream>
#include<string>
#pragma comment(lib,"Projoct1.lib")
using namespace std;

int main()
{

	int sum = fnMySum(3, 7);

	cout << "sum =" << sum << endl;



	system("pause");
    return 0;
}

