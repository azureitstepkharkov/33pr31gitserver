#pragma once
#include"BoardMatrix.h"
#include"GameBoard.h"
class GameController
{
private:
	GameBoard * gameBoard;
	BoardMatrix* boardMatrix;
	int x;
	int y;
	int counter=0;
public:
	GameController()
	{
		gameBoard = new GameBoard();
		boardMatrix = new BoardMatrix();
	}
	void Game()
	{
		cout << "¬ведите номера €чейки, в которую ставим ";

		if (counter % 2 == 0)
			cout << "X" << endl;
		else
			cout << "O" << endl;

		cin >> x;
		cin >> y;
		counter++;
		gameBoard->DrawGameBoard(boardMatrix->getBoard());
	}
	void printResult()
	{
		if (counter > 0)
		{
			cout << "result";
		}
	}

	void haveWinner()
	{

	}

	~GameController()
	{
		delete gameBoard;
		delete boardMatrix;
	}
};

