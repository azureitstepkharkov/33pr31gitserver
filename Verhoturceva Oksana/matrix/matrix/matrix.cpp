// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

int matrix()
{
	int const s = 3;
	int a[s][s];

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			std::cout << a[i][j] << std::endl;
		}
	}
}
//print_matrix
int main()
{
	//matrix();
    return 0;
}

