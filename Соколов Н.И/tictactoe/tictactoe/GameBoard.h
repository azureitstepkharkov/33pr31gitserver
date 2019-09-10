#pragma once
#include <iostream>
#include <string>
using namespace std;
class GameBoard
{
private:
	const int N=3;
public:
	GameBoard()
	{
		for (int i(0); i < N; i++)
		{
			for (int j(0); j < N; j++)
				cout << "_" << " ";
			cout << endl;
		}																										   
	}
	GameBoard(int ** board)
	{
		DrawGameBoard(board);
	}
	void DrawGameBoard(int ** board)
	{
		for (int i(0); i < N; i++)
		{
			for (int j(0); j < N; j++)
			{
				if (board[i][j] == 2)
				{
					cout << "_" << " ";
				}
				else if(board[i][j] == 1)
					cout << "<table>\n"<<"\t<tr>\n\t<td>" << " X " << "<\\td>\n\t<\\tl>\n\t<tr>\n\t\n<table> \n";
				else if (board[i][j] == 0)
					cout << "<table>\n" << "\t<tr>\n\t<td>" << " O " << "<\\td>\n\t<\\tl>\n\t<tr>\n\t\n<table> \n ";

			}
			cout << endl;
			
		}
		
	}
	virtual ~GameBoard() {};
	int getN()
	{
		return this->N;
	}
};

