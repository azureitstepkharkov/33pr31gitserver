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
					cout << "X ";
				else if (board[i][j] == 0)
					cout  << "O " ;

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

