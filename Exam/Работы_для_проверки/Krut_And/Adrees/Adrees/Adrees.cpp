// Adrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm> //хранить алгоритмы сортировки поиска
#include<vector> //класс динамический массив, замена int* paray = new int[N]
#include<functional> //здесь хроанятся функтары. Это выражения вида: greater<int>(), greater_equal<int>(), less_equal<int>()
#include<string> //клаяя для работы со строками, замена char*
#include<list> //класс двух направленый список, замена программирования списка в ручную (см. проект ListItem)
#include"Collection.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Collection info(
		"Харьков", "Победа", "48Б", "128Б", 
		"Мужской", "17", "Андрей", "Крутовой",
		"пр.Победы", "380678015436", "Программист",
		"2343 2451 4534 2313", "4500", "Разработка чего либо", "Андрей", "Рома"
	);

	/*info.Print();
	cout << "===========================" << endl;
	h_entinity.Print();
	cout << "===========================" << endl;
	a_entinity.Print();
	cout << "===========================" << endl;
	person.Print();
	cout << "===========================" << endl;
	emp.Print();*/

	ofstream ofs("Adress.txt");
	ofs << info << endl;
	cout << info << endl;
	ofs.close();

	cout << endl;

	Deportment dep("IT", "BOSS");
	dep.set_sotrudniki(Employee("Андрей", "Крутовой", "2343 2451 4534 2313"));
	dep.get_sotrudniki();
	cout << endl;

	vector<Employee*> MEN;

	Employee* info1 = new Collection(
		"Харьков", "Победа", "48Б", "128Б",
		"Мужской", "17", "Андрей", "Крутовой",
		"пр.Победы", "380678015436", "Программист",
		"2343 2451 4534 2313", "4500", "Разработка чего либо", "Андрей", "Рома"
	);

	MEN.push_back(info1);

	vector<Employee*>::iterator ptr;

	cout << "Before sorting: " << endl;
	for (ptr = MEN.begin(); ptr < MEN.end(); ptr++)
		cout << *(*ptr) << " ";

	system("pause");
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
