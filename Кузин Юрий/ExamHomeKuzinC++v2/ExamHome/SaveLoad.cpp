#include "SaveLoad.h"
#include <algorithm>
#include<iostream>

void SaveLoad::Save(const std::string path, std::vector<Learner*>& vec)
{
	std::fstream fs;
	fs.open(path, std::fstream::out | std::fstream::app);
	if (!fs.is_open())
	{
		throw std::exception("Some problem occured when oppening file to save");
	}
	else
	{
		std::for_each(vec.begin(), vec.end(), [&](Learner *obj) {
			if (obj->whoIs() == "Graduate")
				fs << *(dynamic_cast<class Graduate*>(obj)) << std::endl;
			else if (obj->whoIs() == "Student")
				fs << *(dynamic_cast<class Student*>(obj)) << std::endl;
			else
				fs << *obj << std::endl;
		});
		
	}
	fs.close();
}



void SaveLoad::Load(const std::string path, std::vector<Learner*>& vec)
{
	std::fstream fs;
	fs.open(path, std::fstream::in);
	if (!fs.is_open())
	{
		throw std::exception("Some problem occured when oppening file to save");
	}
	else
	{
		std::string lineContent;
		while (!fs.eof())
		{
			std::getline(fs, lineContent);
			//Count the words in stringstream
			int counter(0);
			std::stringstream tempContent(lineContent);
			std::string temp;
			while (tempContent >> temp) ++counter;

			if (!counter)
				//empty line,nextline,end of file etc..
				continue; 
			if (counter == 5)
				vec.push_back(new Learner(lineContent));
			else if (counter == 7)
				vec.push_back(new Student(lineContent));
			else
				vec.push_back(new Graduate(lineContent));
		}
	}
	fs.close();
}

SaveLoad::~SaveLoad()
{
}
