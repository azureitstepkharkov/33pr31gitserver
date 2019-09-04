#pragma once
#include<iostream>
#include<string>

using namespace std;

class GameBoard
{
private:
	const int N = 3;
public:
	GameBoard() //Конструктор по умолчанию. Целое поле занимаем "_"
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

	GameBoard(int **Board)
	{
		DrawGameBoard(Board);
	};

	void DrawGameBoard(int **Board) //Занимаем поле либо X либо 0 либо ничего
	{
		for (int i = 0; i < N; i++) // строка поля
		{
			for (int j = 0; j < N; j++) // столбец поля
			{
				if (Board[i][j] == 2)
				{
					cout << "_" << " ";
				}
				else
				if (Board[i][j] == 1)
				{
					cout << "X" << " ";
				}
				else
				if (Board[i][j] == 0)
				{
					cout << "O" << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	virtual ~GameBoard()
	{

	}
};

