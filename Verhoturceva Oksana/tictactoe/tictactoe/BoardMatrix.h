#pragma once
#include<iostream>
#include<string>
using namespace std;
class BoardMatrix
{
protected:

	const int N = 3;
	int** matrix;
public:
	BoardMatrix()
	{
		matrix = new int*[N];
		for (int i = 0; i < N; i++)
		{
			matrix[i] = new int[N];
	    }
		//начального заполнения 2
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = 2;
			}
			
		}

	};
	void tester()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = rand() % 2;
			}
		}
	}
	virtual ~BoardMatrix()
	{
		for (int i = 0; i < N; i++)
		{
			delete matrix[i];
		}
		delete[] matrix;
	};
	//operator[]
	int**getBoard()
	{ return matrix; }
};

