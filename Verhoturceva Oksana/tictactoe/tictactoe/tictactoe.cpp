// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"GameController.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Hello from tictactoe game"<<endl;
	GameController* tictactoeGame = new GameController();
	bool haveWinner = false;
	do
	{
		//tictactoeGame.printResult();//вывожу текущую игровую ситуацию
		tictactoeGame->Game();//спрашиваю куда ставить Х или 0
		//haveWinner = tictactoeGame.haveWinner();//ищу линию Х или 0
	}while(!haveWinner);
	delete tictactoeGame;
	system("pause");
    return 0;
}

