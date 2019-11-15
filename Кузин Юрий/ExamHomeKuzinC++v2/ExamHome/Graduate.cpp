#include "Graduate.h"



Graduate::Graduate(const std::string & graduateInformation)
{
	std::stringstream graduateStream(graduateInformation);
	graduateStream >> fname >> lname >> pname >> email >> phone >> inst >> dept >> date >> diss;
}

Graduate::Graduate() : Student::Student(), date(), diss()
{
}

Graduate::Graduate(const Student & Source, 
	const char * date, const char * diss) :
	Student::Student(Source), date(date), diss(diss)
{
}

Graduate::Graduate(const Student & Source, 
	const std::string & date, const std::string & diss) :
	Student::Student(Source), date(date), diss(diss)
{
}

Graduate::Graduate(const Learner & Source, 
	const char * inst, const char * dept, 
	const char * date, const char * diss) :
	Student::Student(Source, inst, dept), date(date), diss(diss)
{
}

Graduate::Graduate(const Learner & Source, 
	const std::string & inst, const std::string & dept, 
	const std::string & date, const std::string & diss) :
	Student::Student(Source, inst, dept), date(date), diss(diss)
{
}

Graduate::Graduate(const char * fname, const char * lname, const char * pname,
	const char * email, const char *phone,
	const char * inst, const char * dept, 
	const char * date, const char * diss):
	Student(fname,lname,pname,email,phone,inst,dept), date(date), diss(diss)
{
}

Graduate::Graduate(const std::string & fname, const std::string & lname, const std::string & pname,
	const std::string & email, const std::string & phone, 
	const std::string & inst, const std::string & dept, 
	const std::string & date, const std::string & diss) :
	Student(fname, lname, pname, email, phone, inst, dept), date(date), diss(diss)
{
}

Graduate::Graduate(const Graduate & Source) :
	Student::Student(Source), date(Source.date), diss(Source.diss)
{
}


Graduate & Graduate::operator=(const Graduate & Src)
{
	Student::operator=(Src);
	date = Src.date;
	diss = Src.diss;
	return *this;
}


const std::string & Graduate::getDa()
{
	return date;
}

const std::string & Graduate::getDi()
{
	return diss;
}

Graduate::~Graduate()
{
}

std::ostream & operator<<(std::ostream & os, const Graduate & Source)
{
	os << Source.fname << " " << Source.lname << " " << Source.pname << " "
		<< Source.email << " " << Source.phone << " "
		<< Source.inst << " " << Source.dept << " "
		<< Source.date << " " << Source.diss;
	return os;
}

std::istream & operator>>(std::istream & in, Graduate & Source)
{
	in >> Source.fname >> Source.lname >> Source.pname >> Source.email >> Source.phone 
		>> Source.inst >> Source.dept
		>> Source.date >> Source.diss;
	return in;
}
