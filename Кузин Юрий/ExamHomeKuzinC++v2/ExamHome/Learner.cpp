#include "Learner.h"



Learner::Learner(const std::string & learnerInformation)
{
	std::stringstream learnerStream(learnerInformation);
	learnerStream >> fname >> lname >> pname >> email >> phone;
}

Learner::Learner() : fname(), lname(), pname(), email(), phone()
{
}

Learner::Learner(const char * fn, const char * ln, const char * pn, const char * em, const char * ph) :
	fname(fn), lname(ln), pname(pn), email(em), phone(ph)
{
}

Learner::Learner(const std::string & fn, const std::string & ln, const std::string & pn, const std::string & em, const std::string & ph) :
	fname(fn), lname(ln), pname(pn), email(em), phone(ph)
{
}

Learner::Learner(const Learner & Src) :
	fname(Src.fname), lname(Src.lname), pname(Src.pname), phone(Src.phone), email(Src.email)
{
}

Learner & Learner::operator=(const Learner & Src)
{
	fname = Src.fname;
	lname = Src.lname;
	pname = Src.pname;
	phone = Src.phone;
	email = Src.email;


	return *this;
}

const std::string & Learner::getFn()
{
	return fname;
}

const std::string & Learner::getLn()
{
	return lname;
}

const std::string & Learner::getPn()
{
	return pname;
}

const std::string & Learner::getPh()
{
	return phone;
}

const std::string & Learner::getEm()
{
	return email;
}



Learner::~Learner()
{
}

std::ostream & operator<<(std::ostream & os, const Learner & Source)
{
	os << Source.fname << " "
		<< Source.lname << " "
		<< Source.pname << " "
		<< Source.email << " "
		<< Source.phone;
	return os;
}

std::istream & operator>>(std::istream & in, Learner & Source)
{
	in >> Source.fname >> Source.lname >> Source.pname >> Source.email >> Source.phone;
	return in;
}
