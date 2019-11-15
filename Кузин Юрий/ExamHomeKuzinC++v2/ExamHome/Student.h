#pragma once
#include "Learner.h"
class Student : public Learner
{
protected:
	std::string
		//Institute name
		inst,
		//Departament name
		dept;
public:
	using Learner::operator=;

	//Singleline constructor
	Student(const std::string &studentInformation);
	//Default constructor
	Student();
	//Overloaded with basic Learner & char
	Student(const Learner & Src, const char *inst, const char*dept);
	//Overloaded with base class learner and string
	Student(const Learner & Src, const std::string & inst, const std::string & dept);
	//Overloaded char constructor
	Student(const char *fn,	const char *ln,	const char *pn,	const char *em,	const char *ph,
		const char *in,	const char *de);
	//Overloaded string constructor
	Student(const std::string &fn, const std::string &ln, 
		const std::string &pn, const std::string &em,const std::string &ph,
		const std::string &in, const std::string &de);
	//Copy constructor
	Student(const Student & Src);

	//Assignment operator
	Student & operator = (const Student & Src);
	//Boolean equality operators
	inline bool operator == (const Student &Rhs)
	{
		return (
			Learner::operator==(Rhs)
			&& (inst == Rhs.inst)
			&& (dept == Rhs.dept));
	}
	inline bool operator != (const Student &Rhs)
	{
		return !(*this == Rhs);
	}
	//Overloaded ostream and istream operators
	friend std::ostream& operator << (std::ostream &os, const Student &Source);
	friend std::istream& operator >> (std::istream &in, Student &Source);


	//get's Func-s
	virtual const std::string &getIn();
	virtual const std::string &getDe();


	//Temporatory func
	virtual std::string whoIs() {
	/*	const type_info &t = typeid(dynamic_cast<Student*>(this));
		return std::string(t.name());*/
		return std::string("Student");
	}
	~Student();



};

