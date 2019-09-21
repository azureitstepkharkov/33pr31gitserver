// Adr_Anim_Hum_Person.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"ClassRelation.h"
#include<list>
#include<vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	

	vector <Reletion*> Rel;
	Reletion* A1 = new Reletion(
		"Харьков", "шевченко", "343", "63",
		"Мужской", "39", "Андрей", "Острижный",
		"+38-050-302-90-77", "Программист",
		"2222 3333 4444 5555", "5000000");

	Reletion* A2 = new Reletion(
		"Харьков", "шевченко", "343", "63",
		"Мужской", "39", "Андрей", "Острижный",
		"+38-050-302-90-77", "Программист",
		"2222 3333 4444 5555", "5000000");

	Reletion* A3 = new Reletion(
		"Харьков", "шевченко", "343", "63",
		"Мужской", "39", "Андрей", "Острижный",
		"+38-050-302-90-77", "Программист",
		"2222 3333 4444 5555", "5000000");

	Reletion* A4 = new Reletion(
		"Харьков", "шевченко", "343", "63",
		"Мужской", "39", "Андрей", "Острижный",
		"+38-050-302-90-77", "Программист",
		"2222 3333 4444 5555", "5000000");

	Reletion* A5 = new Reletion(
		"Харьков", "шевченко", "343", "63",
		"Мужской", "39", "Андрей", "Острижный",
		"+38-050-302-90-77", "Программист",
		"2222 3333 4444 5555", "5000000");
	Rel.push_back(A1);
	Rel.push_back(A2);
	Rel.push_back(A3);
	Rel.push_back(A4);
	Rel.push_back(A5);
	///////////////////
	vector <Reletion*>::iterator ptr;
	cout << endl << endl << "Show Information : " << endl;
	for (ptr = Rel.begin(); ptr < Rel.end(); ptr++)
		cout << *(*ptr) << " ";
	//////////////////////////
	// деструктор
	for (int i = 0; i < 5; i++)
	{
		delete Rel[i];
	}



	//Reletion info(
	//	"Харьков", "шевченко", "343", "63",
	//	"Мужской", "39", "Андрей", "Острижный",
	//	 "+38-050-302-90-77", "Программист",
	//	"2222 3333 4444 5555", "5000000"
	//);
	//
	//
	//ofstream ofs("Adress.txt");
	//ofs << info << endl;
	//cout << info << endl;
	//ofs.close();


	system("pause");
	////

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
