// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"GameController.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "Hello from tictactoe game!\n";
	GameController* tictactoeGame = new GameController();
	bool haveWinner = false;
	do
	{
		//tictactoeGame.printResult();//Вывожу текущую игровую ситуацию
		tictactoeGame->Game();// спрашиваю куда ставить X или O
		//haveWinner = tictactoeGame.haveWinner();//ищу линию X или O
	} while (haveWinner);
	delete tictactoeGame;
    return 0;
}

