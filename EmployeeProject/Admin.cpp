#include "Admin.h"

Admin::Admin(const char* id, double basic,const char *name, const char *addr, double incentive) :Employee(id, basic, name, addr)
{
	mIncentive = incentive;
}

void Admin::update()
{
	Employee::update();
	int empIncentive;
	cout << "Enter Employee Incentive::";
	cin >> empIncentive;
	setIncentive(empIncentive);
}

void Admin::setIncentive(double incentive)
{
	mIncentive = incentive;
}
double Admin::getIncentive()
{
	return mIncentive;
}

void Admin::display()
{
	Employee::display();
	cout << "Salary: " << calSal() << endl;
}

double Admin::calSal() 
{
	return getBasic() + mIncentive;
}

Admin::~Admin()
{
}
