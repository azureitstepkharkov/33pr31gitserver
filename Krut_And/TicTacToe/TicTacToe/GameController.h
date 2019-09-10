#pragma once
#include"BootMatrix.h"
#include"GameBoard.h"

int** getBoardMatrix();

class GameController : public BootMatrix
{
private:
	GameBoard* gameboard;
	BootMatrix* boardMatrix;
	int x;
	int y;
	int counter;
	const int N = 3;
	int** matriz;
	int** print_matriz;
public:
	GameController()
	{
		gameboard = new GameBoard();
		boardMatrix = new BootMatrix();
	};

	void Game()
	{
		cout << "Введите номер ячейки, в которую ставим" << endl;;
		if (counter % 2 == 0)
		{
			cout << "X" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
		cin >> x; // строка
		cin >> y; // столбец
		counter++;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (counter % 2 == 0)
				{
					matriz[i][j] = 1;
				}
				else
				{
					matriz[i][j] = 0;
				}
			}
		}
	}

	void printResult()
	{
		//system("cls");

		matriz = getBoardMatrix();

		for (int i = 0; i < N; i++) // строка поля
		{
			for (int j = 0; j < N; j++) // столбец поля
			{
				if (matriz[i][j] == 2)
				{
					cout << "_" << " ";
				}
				else
				if (matriz[i][j] == 1)
				{
					cout << "X" << " ";
				}
				else
				if (matriz[i][j] == 0)
				{
					cout << "O" << " ";
				}
			}
			cout << endl;
		}
	}

	~GameController()
	{
		delete gameboard;
		delete boardMatrix;
	};
};