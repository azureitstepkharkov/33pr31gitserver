#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Graduate.h"
class SaveLoad
{
private:
	SaveLoad(const SaveLoad &src) {}
public:
	SaveLoad() {}
	void Save(const std::string path, std::vector<Learner*> &vec);
	void Load(const std::string path, std::vector<Learner*> &vec);
	~SaveLoad();
};

