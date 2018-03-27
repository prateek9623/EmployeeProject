#include "Header.h"

class Employee
{
	string mEid;
	double mBasic;
	string mName;
	string mAddress;
public:
	Employee(const char*, double, const char *, const char *);

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
	
	/*void virtual setincentive(double) {};
	double virtual getincentive() { return 0.0; }
	int virtual  getexhrs() { return 0; }
	double virtual getcostperhrs() { return 0.0; }
	double virtual getcommision() { return 0.0; }
	int virtual getsales() { return 0; }
	void virtual setexhrs(int) {};
	void virtual setcostperhrs(double) {};
	void virtual setcommision(double) {};
	void virtual setsales(int) {};
*/
	~Employee();
};