#include "Header.h"

class Employee
{
	string mEid;
	double mBasic;
	string mName;
	string mAddress;
public:
	Employee(const char*, double, const char *, const char *);
	Employee();
	const char* getId();

	void setBasic(double);
	double getBasic();

	void setName(const char *);
	const char * getName();

	void setAddr(const char *);
	const char * getAddr();

	void virtual display()=0;

	double virtual calSal() = 0;
	void virtual update() = 0;
	
	bool virtual writeToFile(ostream&)=0;
	bool virtual readFromFile(istream&) = 0;

	

	~Employee();

	protected:

		void setId( string );
	
};