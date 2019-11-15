#pragma once
#include "Student.h"
class Graduate : public Student
{
private:
	std::string
		//datetime
		date,
		//dessertation name
		diss;
public:
	using Student::operator=;

	//Singleline constructor
	Graduate(const std::string &graduateInformation);
	//default constructor
	Graduate();
	//Overloaded constructors
	Graduate(const Student & Source, 
		const char *date, const char *diss);
	Graduate(const Student & Source,
		const std::string &date, const std::string &diss);
	Graduate(const Learner & Source,
		const char *inst, const char *dept, 
		const char *date, const char *diss);
	Graduate(const Learner & Source,
		const std::string &inst, const std::string &dept,
		const std::string &date, const std::string &diss);
	Graduate(const char *fname, const char *lname, const char *pname,
		const char *email, const char *phone,
		const char *inst, const char *dept,
		const char *date, const char *diss);
	Graduate(const std::string &fname, const std::string &lname, const std::string &pname,
		const std::string &email, const std::string &phone,
		const std::string &inst, const std::string &dept,
		const std::string &date, const std::string &diss);
	//copy constructor
	Graduate(const Graduate & Source);

	//Assignment operator
	Graduate & operator = (const Graduate & Src);

	//Boolean equality operators
	inline bool operator == (const Graduate &Rhs)
	{
		return (
			Student::operator==(Rhs)
			&& (date == Rhs.date)
			&& (diss == Rhs.diss));
	}
	inline bool operator != (const Graduate &Rhs)
	{
		return !(*this == Rhs);
	}

	//Overloaded ostream and istream operators
	friend std::ostream& operator << (std::ostream &os, const Graduate &Source);
	friend std::istream& operator >> (std::istream &in, Graduate &Source);

	//Set&Get

	virtual const std::string &getDa();
	virtual const std::string &getDi();

	//Temporatory func
	virtual std::string whoIs() {
		/*const type_info &t = typeid(dynamic_cast<Learner*>(this));
		return std::string(t.name());*/
		return std::string("Graduate");
	}
	~Graduate();
};

