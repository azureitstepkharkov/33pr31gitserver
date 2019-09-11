#pragma once

#include"BoardMatrix.h"
#include"GameBoard.h"
class GameController
{
private:
	GameBoard* gameBoard;
	BoardMatrix* boardMatrix;
	int x;
	int y;
	int countr;
	

public:
	GameController()
	{
		gameBoard = new GameBoard();
		boardMatrix = new BoardMatrix();
	}
	virtual ~GameController()
	{
		delete gameBoard;
		delete boardMatrix;
	};

	void Game()
	{
		
		cout << "input numbers cell" << endl;
		if (countr % 2 == 0)
		{

				cout << "X" << endl;
				cin >> x;
				cin >> y;
				if (checPick(boardMatrix->GetDoard(), x, y))
				{
					boardMatrix->SET_BoardMatrix(x, y, 1);
				}
				else
				{
					cout << "ZANYTO" << endl;
					return Game();
					
				}
			
		}
		else
		{
				cout << "O" << endl;
				cin >> x;
				cin >> y;
				if (checPick(boardMatrix->GetDoard(), x, y))
				{
					boardMatrix->SET_BoardMatrix(x, y, 0);
				}
				else
				{
					cout << "ZANYTO" << endl;
					return Game();
					
				}
			
			
		}
		countr++;
		cout << countr << endl;
		
		
		
	}
	void printresult()
	{
		gameBoard->DrawGameBoard(boardMatrix->GetDoard());
	}
	bool checPick(int ** mt,int x,int y)
	{
		if (mt[x][y] == 2)
		{
			return true;
		}
		else return false;
	}

	bool CheckMatrix(int ** checM)
	{
		
		int rez(0);
		for (int i(0); i < 3; i++)
		{
			for (int j(0); j < 2; j++)
				if (checM[i][j] == checM[i][j + 1])
					rez++;
			if (rez == 2)
				return rez;
			else rez = 0;

			for (int j(0); j < 2; j++)
				if (checM[j][i] == checM[j + 1][i])
					rez++;
			if (rez == 2)
				return true;
			else rez = 0;
		}
		return false;
	}

	bool haveViner()
	{
		
		bool d = false;
		if (countr >=5)
		{
			int ** checM = boardMatrix->GetDoard();
			if (CheckMatrix(checM))
			{
				cout << "POBEDA" << endl;
				return 1;
			}
			x = 0;
			y = 0;
			if (checM[x][y] == checM[x + 1][y + 1] && checM[x][y] == checM[x + 2][y + 2] 
				||checM[x + 2][y] == checM[x + 1][y + 1] && checM[x + 2][y] == checM[x][y + 2])
			{
				cout << "POBEDA" << endl;
				return 1;
			}
			return false;		
		}
		if (countr == 9)
		{
			cout << "NECHY" << endl;
			return true;
		}
		return false;
		
	}
};

