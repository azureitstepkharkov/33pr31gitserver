#include "Filter.h"



Filter & Filter::eraseType(const char * classname)
{
	auto it = std::remove_if(origin.begin(), origin.end(), [classname](Learner *obj)
	{
		return obj->whoIs() == classname;
	});
	origin.erase(it, origin.end());
	return *this;
}

std::vector<Learner*> Filter::all()
{
	return origin;
}

Filter::~Filter()
{
}
