#include "Student.h"



Student::Student(const std::string & studentInformation)
{
	std::stringstream studentStream(studentInformation);
	studentStream >> fname >> lname >> pname >> email >> phone >> inst >> dept;
}

Student::Student() : Learner::Learner(), inst(), dept()
{
}

Student::Student(const Learner & Src, const char * inst, const char * dept) :
	Learner::Learner(Src), inst(inst), dept(dept)
{
}

Student::Student(const Learner & Src, const std::string & inst, const std::string & dept) :
	Learner::Learner(Src), inst(inst), dept(dept)
{
}

Student::Student(const char * fn, const char * ln, const char * pn, const char * em, const char * ph, const char * in, const char * de) :
	Learner::Learner(fn, ln, pn, em, ph), inst(in), dept(de)
{
}

Student::Student(const std::string & fn, const std::string & ln, const std::string & pn, const std::string & em, const std::string & ph, const std::string & in, const std::string & de) :
	Learner::Learner(fn, ln, pn, em, ph), inst(in), dept(de)
{
}

Student::Student(const Student & Src) : Learner::Learner(Src), inst(Src.inst), dept(Src.dept)
{
}

Student & Student::operator=(const Student & Src)
{
	Learner::operator=(Src);
	inst = Src.inst;
	dept = Src.dept;
	return *this;
}


const std::string & Student::getIn()
{
	return inst;
}

const std::string & Student::getDe()
{
	return dept;
}

Student::~Student()
{
}

std::ostream & operator<<(std::ostream & os, const Student & Source)
{
	os << Source.fname << " " << Source.lname << " " << Source.pname << " "
		<< Source.email << " " << Source.phone << " "
		<< Source.inst << " " << Source.dept;
	return os;
}

std::istream & operator>>(std::istream & in, Student & Source)
{
	in >> Source.fname >> Source.lname >> Source.pname >> Source.email >> Source.phone >> Source.inst >> Source.dept;
	return in;
}
