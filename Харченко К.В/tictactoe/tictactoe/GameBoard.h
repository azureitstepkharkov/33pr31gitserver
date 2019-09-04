#pragma once
#include<iostream>
#include<string>
using namespace std;
class GameBoard
{
private:
	const int N = 3;
public:
	GameBoard()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << "_" << " ";
			}
			cout << endl;
		}
	};
	GameBoard(int** board)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

			}
		}
	};
	void DrawGameBoard(int** board)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (2 == board[i][j])
				{
					cout << "_" << " ";
				}
				if (1 == board[i][j])
				{
					cout << "X" << " ";
				}
				if (0 == board[i][j])
				{
					cout << "O" << " ";
				}
			}
			cout << endl;
		}
	}
	virtual ~GameBoard() {};
};

