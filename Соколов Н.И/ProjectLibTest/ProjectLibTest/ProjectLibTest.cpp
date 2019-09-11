#include "pch.h"
#include<Windows.h>
#include <iostream>
#include<string>
#include"myfunctions.h"
#pragma comment(lib,"Project1.lib")
using namespace std;
int main()
{
   cout << "Hello World!\n"; 
   int sum = fnMySum(3, 7);
   cout << "sum = " << sum << endl;
}


