// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<fstream>
#include<ostream>
using namespace std;
class Matrix
{
const int NumberSyse = 3;
int  Arr [NumberSyse];


public:


	friend ostream& operator << (ostream& out_data_1, Matrix& m)
	{
		out_data << "<tr> <td> " << m.Arr[i] <<"<\td> <<\tr> "<< endl;

		return out_data;
	};
	~Matrix() {};
};


int main()
{
    return 0;
}

