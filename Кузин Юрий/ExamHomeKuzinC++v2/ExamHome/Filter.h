#pragma once
#include <vector>
#include <algorithm>
#include "Graduate.h"
class Filter
{
private:
	std::vector<Learner*> origin;
public:
	Filter(const std::vector<Learner*> &src) :origin(src) {};

	Filter & eraseType(const char *classname);
	std::vector<Learner*> all();
	~Filter();
};

