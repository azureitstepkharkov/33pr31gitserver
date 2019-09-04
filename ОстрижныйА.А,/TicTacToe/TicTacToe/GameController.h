#pragma once
#include"BoaedMatrix.h"
#include"GameBoard.h"
#include"GameController.h"

class GameController
{
private:
	GameBoard * gameBord;
	BoardMatrix* boardMatrix;
	int x;
	int y;
	
	int counter;

public:

	GameController()
	{
		gameBord = new GameBoard();
		boardMatrix = new BoardMatrix();
	};
	void Game()
	{
		cout << "¬ведите номера €чейки, в которую ставим ";
		if (counter % 2 == 0)
		{
			cout << "0" << endl;
		}
		cin >> x;
		cin >> y;
		counter++;
	}
	// метод дл€ теста
	
	~GameController()
	{
		delete gameBord;
		delete boardMatrix;
	};
};

