#include "Employee.h"
class Admin :
	public Employee
{
public:
	double mIncentive;
public:
	//base::long id, double basic, const char *name, const char *add derived:: double incentive.
	Admin(const char*, double, const char *, const char *, double);
	Admin() :Employee() {}
	void update();
	void setIncentive(double);
	double getIncentive();
	void display();
	double calSal();
	bool virtual writeToFile(ostream&);
	bool virtual readFromFile(istream&);
	~Admin();
};
