// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include"GameController.h"
#include"BoaedMatrix.h"
#include"GameBoard.h"
using namespace std;

int main()
{
	setlocale(LC_ALL ,"rus");
	GameController* tictactoeGame = new GameController();
	bool haveWinner = false;
	do
	{
		//tictactoeGame.printResult(): //вывод текущей игровой ситуации
		tictactoeGame->Game();// спрашиваю куда ставить Х или 0
		// haveWinner = tictactoeGame.haveWinner(); // ищу линию Х или 0

	} while (!haveWinner);
	delete tictactoeGame;

    return 0;
	system("pause");
}

