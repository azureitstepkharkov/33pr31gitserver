#pragma once
#include <string>
#include <sstream> 
class StringHelper
{
public:
	StringHelper() {};
	~StringHelper() {};
	static std::string int2str(int x)
	{
		std::stringstream ss;
		ss << x;
		return ss.str();
	}
};

