// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"GameController.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Hello from tictactoe game\n";
	GameController* tictactoeGame = new GameController();
	bool haveWinner = false;
	do
	{
		//tictactoeGame->GameTest();
		tictactoeGame->printResult();//вывожу текущую игровую ситуацию
		tictactoeGame->Game();//спрашиваю куда ставить Х или О
		//haveWinner = tictactoeGame.haveWinner();//ищу линию Х или О
	} while (!haveWinner);
	delete tictactoeGame;
	system("pause");
}

