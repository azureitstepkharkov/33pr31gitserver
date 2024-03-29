#pragma once

#include"BoardMatrix.h"
#include"GameBoard.h"
#include<fstream>
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
	void zapis(int **obj)
	{
		
		ofstream os;
		
		os.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt");
		if (!os.is_open()) cout << "Not open\n";
		if (os.is_open())
		{
			countr++;
			os << countr << "#" << endl;
			
				for (int i(0); i < 3; i++)
				{
					for (int j(0); j < 3; j++)
					{
						os << obj[i][j] << "$";;
					}
					os << endl;
					
				}
			
		}
		
		os.close();
	}


	bool readFile(int ** abs)
	{
		
		ifstream fin;
		ifstream fin1;
		fin.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt");
		fin1.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt");
		if (!fin.is_open())
		{
			cout << "NOT OPEN" << endl;
			return false;
		}
		else
		{
			cout << "OPEN " << endl;

			string OBG;
			string str;
			string oo;
			if (fin.peek() == EOF)
			{
				return true;
			}
			
			getline(fin, str);
			getline(fin1, oo);
			for (int i(0); i < 3; i++)
			{
				getline(fin, str);

				if (str.length() > 0)
				{
					int pos(0);
					for (int j(0); j < 3; j++)
					{
						int pos_end = str.find("$", pos);
						OBG = str.substr(pos, pos_end - pos);
						pos = pos_end + 1;
						abs[i][j] = atoi(OBG.c_str());
					}
				}

			}
			
			if (oo.length() > 0)
			{
				int pos_end = oo.find("#");
				OBG = oo.substr(0,pos_end);
				countr = atoi(OBG.c_str());
			}
		}
		gameBoard->DrawGameBoard(abs);
		fin.close();
		return false;

	}
	void Game()
	{

		cout << "input numbers cell" << endl;
		
		
			if (readFile(boardMatrix->GetDoard()))
			{
				cout << "O" << endl;

				cin >> x;
				cin >> y;
				readFile(boardMatrix->GetDoard());
				if (countr % 2 != 0) {
					if (checPick(boardMatrix->GetDoard(), x, y))
					{

						boardMatrix->SET_BoardMatrix(x, y, 0);
						zapis(boardMatrix->GetDoard());

					}
					else
					{
						cout << "ZANYTO" << endl;
						return Game();

					}
				}
				else
				{
					cout << "Waiting yur partner" << endl;
					readFile(boardMatrix->GetDoard());
					return Game();
				}
				/*if (countr % 2 != 0) {
					if (checPick(boardMatrix->GetDoard(), x, y))
					{

						boardMatrix->SET_BoardMatrix(x, y, 0);
						zapis(boardMatrix->GetDoard());

					}
					else
					{
						cout << "ZANYTO" << endl;
						return Game();

					}
				}
				else
				{
					cout << "Waiting yur partner" << endl;
					readFile(boardMatrix->GetDoard());
					return Game();
				}*/
			}
			else {
				
				
				if (CheckMatrix(boardMatrix->GetDoard()))
				{
					cout << "GAMAOWER" << endl;
					fstream ofs;
					ofs.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt", ios::out | ios::trunc);
					ofs << "";
					haveViner();
				}
				else
				{
					cout << "O" << endl;
					cin >> x;
					cin >> y;
					readFile(boardMatrix->GetDoard());
					if (countr % 2 != 0) {
						if (checPick(boardMatrix->GetDoard(), x, y))
						{

							boardMatrix->SET_BoardMatrix(x, y, 0);
							zapis(boardMatrix->GetDoard());

						}
						else
						{
							cout << "ZANYTO" << endl;
							return Game();

						}
					}
					else
					{
						cout << "Waiting yur partner" << endl;
						readFile(boardMatrix->GetDoard());
						return Game();
					}
					
					/*if (countr % 2 != 0) {
						if (checPick(boardMatrix->GetDoard(), x, y))
						{

							boardMatrix->SET_BoardMatrix(x, y, 0);
							zapis(boardMatrix->GetDoard());

						}
						else
						{
							cout << "ZANYTO" << endl;
							return Game();

						}
					}
					else
					{
						cout << "Waiting yur partner" << endl;
						readFile(boardMatrix->GetDoard());
						return Game();
					}*/
				}
				
				
					
			}
		
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
				if (checM[i][j] == checM[i][j + 1]&& checM[i][j + 1]!=2)
					rez++;
			if (rez == 2)
				return true;
			else rez = 0;

			for (int j(0); j < 2; j++)
				if (checM[j][i] == checM[j + 1][i]&& checM[j + 1][i]!=2)
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
				fstream ofs;
				ofs.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt", ios::out | ios::trunc);
				ofs << "";
				return true;
			}
			cout << checM << endl;
			x = 0;
			y = 0;
			if (checM[x][y] == checM[x + 1][y + 1] && checM[x][y] == checM[x + 2][y + 2] 
				||checM[x + 2][y] == checM[x + 1][y + 1] && checM[x + 2][y] == checM[x][y + 2]&& checM[x][y + 2]!=2&& checM[x][y])
			{
				cout << "POBEDA" << endl;
				fstream ofs;
				ofs.open("D:\\_testSVNServer\\SokolovNikolai\\rezalt.txt", ios::out | ios::trunc);
				ofs << "";

				return true;
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

