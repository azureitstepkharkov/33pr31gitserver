#include <iostream>
#include <vector>
#include "Graduate.h"
#include "SaveLoad.h"
#include "Filter.h"
#include <iterator>


//used to dynamic cast obj before cout
void cast(Learner *Obj);

int main()
{
	//Test items
	Learner	Learn("Abel", "Janszoon", "Tasman", "Jan@du", " 0-312-055-51-11");
	Learner Learn2("Igor Eremin Ivanovich igorek@ru 8-499-310-10-70");
	Student	Stud(Learn, "Heidelberg", "Biosciences");
	Student Stud2("Anton", "Grebenuk", "Sergeevich", "tohaTheBest@bg", "3-805-721-21-10", "KHAI", "Avia");
	Graduate Grad("Zudenkov Igor Evgenevich zudenko@ru 8-499-311-12-12 MGU Economics 2004.12.01 Forming...");
	Graduate Grad2("Dmitriy", "Malcev", "Andreev", "@brabra", "0-111-832-21-99", "SSTS", "Statistics", "2018-01-01", "noname");

	//Container
	std::vector<Learner*> baseCollection;

	//Fill container
	baseCollection.push_back(new Learner(Learn));
	baseCollection.push_back(new Student(Stud));
	baseCollection.push_back(new Graduate(Grad));
	baseCollection.push_back(new Graduate(Grad2));
	baseCollection.push_back(new Learner(Learn2));
	baseCollection.push_back(new Student(Stud2));


	//Проверка работы отсеивателя предоставляет выборку без указаного класса
	Filter selection(baseCollection);
	std::vector<Learner*> result = selection.eraseType("Student").eraseType("Learner").all();

	std::cout << "#########################################################" << std::endl;
	std::cout << "Selected Collection : " << std::endl << std::endl;
	//Show selected vector
	std::for_each(result.begin(), result.end(), cast);
	//for (auto it : result) std::cout << *it << it->whoIs() << std::endl;

	////Обход отсутствия сеттеров

	//{
	//Graduate *changeMe = dynamic_cast<Graduate*>(baseCollection.at(2));
	//const_cast<std::string&>(changeMe->getDi()) = "Test";
	//}
	std::cout << "#########################################################" << std::endl;
	std::cout << "Base Collection : " << std::endl << std::endl;
	//Show original container
	std::for_each(baseCollection.begin(), baseCollection.end(), cast);
	//for (auto it : baseCollection) std::cout << *it << it->whoIs()<<std::endl;
	
	//Class object for save and load
	SaveLoad fileObject;

	//Save base collection to file named base.txt
	try 
	{
	fileObject.Save("base.txt", baseCollection);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	//Whitespace
	std::cout << std::endl;
	std::cout << std::endl;

	//Container for loaded data
	std::vector<Learner*> newCollection;

	//Load from base.txt
	try 
	{
	fileObject.Load("base.txt", newCollection);
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "#########################################################" << std::endl;
	std::cout << "loaded from file Collection : " << std::endl << std::endl;
	//Show new data from file
	std::for_each(newCollection.begin(), newCollection.end(), cast);
	//for (auto it : newCollection)std::cout << *it <<it->whoIs()<< std::endl;

	//Save to another file named test.txt
	try 
	{
	fileObject.Save("test.txt", newCollection);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	//Распечатка с помощью ostream_iterator
	std::cout << "#########################################################" << std::endl;
	std::cout << "Print with ostream_iterator" << std::endl;
	std::ostream_iterator<Learner*> out_it(std::cout, ",!");
	for (std::vector<Learner*>::iterator it = newCollection.begin(); it != newCollection.end(); ++it)
		cast(*it);
	//std::copy(newCollection.begin(), newCollection.end(), *out_it);
	
}

void cast(Learner * Obj)
{
	if (Obj->whoIs() == "Graduate")
	{
		std::cout <<Obj->whoIs() << " : " << std::endl 
			<< *(dynamic_cast<Graduate*>(Obj)) << std::endl;
	}
	else if (Obj->whoIs() == "Student")
	{
		std::cout << Obj->whoIs() << " : " << std::endl 
			<< *(dynamic_cast<Student*>(Obj)) << std::endl;
	}
	else
	{
		std::cout << Obj->whoIs() << " : " << std::endl 
			<< *Obj << std::endl;
	}
	std::cout << std::endl;
}

