#pragma once
#include<iostream>
#include"GameBoard.h"
using namespace std;
//#include<ctime>
class BoardMatrix
{protected:
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
	void GameTest()
	{
		//srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = rand() % 3;
				
			}
		}
	}
    int** getBoard() { return matrix; };
	virtual ~BoardMatrix()
	{
		
		for (int i = 0; i < N; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	};
	//operator[]
	
	
};
