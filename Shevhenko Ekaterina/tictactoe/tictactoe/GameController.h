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
	int counter;
public:
	GameController() 
	{
		gameBoard = new GameBoard();
		boardMatrix = new BoardMatrix();
	};
	void Game()
	{
		cout << "Введите номера ячейки, в которую ставим ";
		if (counter % 2 == 0){ cout << "X" << endl; }
		else		{ cout << "O" << endl; }
		cout << "Горизонталь: ";
		cin >> x;
		cout << "Вертикаль: ";
		cin >> y;
		counter++;
	}
	void printResult()
	{
		cout << endl;
		boardMatrix->GameTest();
		gameBoard->DrawGameBoard(boardMatrix->getBoard());
	}
	void haveWinner() {};
	~GameController()
	{
		delete gameBoard;
		delete boardMatrix;
	};
};

