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
			boardMatrix->SET_BoardMatrix(x, y, 1);
		}
		else
		{
			cin >> x;
			cin >> y;
			cout << "O" << endl;
			boardMatrix->SET_BoardMatrix(x, y, 0);
		}
		countr++;
		cout << countr << endl;
		
		
		
	}
	void printresult()
	{
		gameBoard->DrawGameBoard(boardMatrix->GetDoard());
	}
	
	bool haveViner()
	{
		bool d = false;
		if (countr >=5)
		{
			int ** aa = boardMatrix->GetDoard();

				int wins(0);
				for(int i(0);i<2;i++)
				{
					for (int j(0); j < 2; j++)
					if (aa[i][j] == aa[i][j+1])
						wins++;
					if (wins == 1)
					{
						cout << "POBEDA" << endl;
						return 1;
					}
					wins = 0;
					for (int j(0); j < 2; j++)
						if (aa[j][i] == aa[j+1][i])
							wins++;
					if (wins == 1)
					{
						cout << "POBEDA" << endl;
						return 1;
					}
					if (aa[x][y] == aa[x + 1][y + 1] && aa[x][y] == aa[x + 2][y + 2] || aa[x + 2][y] == aa[x + 1][y + 1] && aa[x + 2][y] == aa[x][y + 2])
									{
										cout << "POBEDA" << endl;
										return 1;	
									}
					
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

