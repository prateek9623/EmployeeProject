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
	cout << "Position::" << "Administrator" << endl;
}

double Admin::calSal() 
{
	return getBasic() + mIncentive;
}

bool Admin::writeToFile(ostream &out)
{
	out << "<Admin>" << endl;
	if (Employee::writeToFile(out))
	{
		try {
			out << mIncentive << endl;
			return true;
		}
		catch (ostream::failure e) {
			return false;
		}
	}
	return false;

}

bool Admin::readFromFile(istream &in)
{
	if (Employee::readFromFile(in)) {
		try {
			in >> mIncentive;
			return true;
		}
		catch (ostream::failure e) {
			return false;
		}
	}
	return false;
}

Admin::~Admin()
{
}

