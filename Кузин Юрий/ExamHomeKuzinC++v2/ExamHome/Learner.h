#pragma once
//include <string> lib for class string
#include <string>
#include <fstream>
#include <typeinfo>
//using sstream for stringstream in singleline constructor
#include <sstream>
class Learner
{
protected:
	std::string
		//first name
		fname,
		//last name
		lname,
		//patronymic
		pname,
		//email
		email,
		//phone num
		phone;
public:

	//Singleline constructor
	Learner(const std::string &learnerInformation);
	//Default constructor
	Learner();
	//Overloaded constructor with const char
	Learner(const char *fn,
		const char *ln,
		const char *pn,
		const char *em,
		const char *ph);
	//reference used to avoid creating a copy for improvement perfomance
	//Overloaded constructor with reference to a string
	Learner(const std::string &fn,
		const std::string &ln,
		const std::string &pn,
		const std::string &em,
		const std::string &ph);
	//Copy constructor
	Learner(const Learner & Src);
	//Assignment operator
	Learner & operator = (const Learner & Src);
	//Equality operators
	inline bool operator == (const Learner &Rhs)
	{
		return ((fname == Rhs.fname)
			&& (lname == Rhs.lname)
			&& (pname == Rhs.pname)
			&& (phone == Rhs.phone)
			&& (email == Rhs.email));
	}
	inline bool operator != (const Learner &Rhs)
	{
		return !(*this == Rhs);
	}


	//Overloaded ostream and istream operators
	friend std::ostream& operator << (std::ostream &os, const Learner &Source);
	friend std::istream& operator >> (std::istream &in, Learner &Source);

	//getFunc-s
	virtual const std::string &getFn();
	virtual const std::string &getLn();
	virtual const std::string &getPn();
	virtual const std::string &getPh();
	virtual const std::string &getEm();

	//temporatory function
	virtual std::string whoIs()
	{
		/*const type_info &t = typeid(dynamic_cast<Learner*>(this));
		return std::string(t.name());*/
		return std::string("Learner");
	}
	~Learner();
};

