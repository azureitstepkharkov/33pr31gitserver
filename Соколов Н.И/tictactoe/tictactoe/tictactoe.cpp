#include "BoardMatrix.h"
#include "pch.h"
#include"GameBoard.h"
#include "GameController.h"

int main()
{
    std::cout << "Hello from tictatoe game"<< endl;
	GameController* tictactoegame = new GameController();
	bool haveViner = false;
	
	

	do
	{
	tictactoegame->Game(); // ��������� ���� ������� � ��� �
	haveViner = tictactoegame->haveViner();// ��� ����� � ��� � 
	
	//
	tictactoegame->printresult();// ������ ������� ������� ��������
	//system("cls");
	
	} while (!haveViner); 
	
	//int XUX = tictactoegame->readFile();
	/*tictactoegame->prin(XUX);*/
	/*cout << XUX;*/
	//delete tictactoegame;
}


