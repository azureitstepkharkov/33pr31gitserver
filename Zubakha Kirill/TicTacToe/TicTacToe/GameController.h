#pragma once
#include "BoardMatrix.h"
#include "GameBoard.h"

class GameController
{
private:
	GameBoard*gameBoard;
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

	void Game() {
		cout << "¬ведите номер €чейки, в которую ставим ";
		if (counter % 2 == 0) {
			cout << "X" << endl;
		}
		else {
			cout << "0" << endl;
		}
		cin >> x;
		cin >> y;
		counter++;
	}

	void printResult(int** board) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << board[i][j];
			}
		}
	};

	 ~GameController() 
	 {
		 delete gameBoard;
		 delete boardMatrix;
	 };
};

