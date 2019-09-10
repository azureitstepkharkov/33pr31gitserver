#pragma once
#include <string>
#include <sstream>

class stringHelper
{
public:
	stringHelper() {};
	~stringHelper() {};

	static std::string int2str(int x) {
		// converts int to string
		std::stringstream ss;
		ss << x;
		return ss.str();
	}

};

