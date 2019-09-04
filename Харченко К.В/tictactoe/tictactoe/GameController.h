#pragma once
#include"BoardMatrix.h"
#include"GameBoard.h"

class GameController
{
private:
	GameBoard* gameBoard;
	BoardMatrix* boardMatrix;
	int x;
	int y;
	int counter;
public:
	GameController()
	{
		gameBoard = new GameBoard();
		boardMatrix = new BoardMatrix();
	};
	void Game()
	{
		cout << "¬ведите номера €чейки, в которую ставим ";
		if (counter % 2 == 0)
		{
			cout << "X" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
		cin >> x;
		cin >> y;
		counter++;
	}

	~GameController()
	{
		delete[] gameBoard;
		delete[]boardMatrix;
	};
};

