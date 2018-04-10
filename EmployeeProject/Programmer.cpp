#include "Programmer.h"

Programmer::Programmer(const char* id, double basic, const char *name,const char  *addr, int exHrs, double cph) : Employee(id, basic, name, addr)
{
	mExtraHrs = exHrs;
	mCostPerHrs = cph;
}

Programmer::Programmer():Employee()
{
}

void Programmer::update()
{
	Employee::update();
	int extraHrs;
	double costPerHrs;
	cout << "Enter Employee Extra hours done::";
	cin >> extraHrs;
	cout << "Enter Employee cost per hours";
	cin >> costPerHrs;
	setExHrs(extraHrs);
	setCostPerHrs(costPerHrs);
}

void Programmer::setExHrs(int hrs)
{
	mExtraHrs = hrs;
}
void Programmer::setCostPerHrs(int cph)
{
	mCostPerHrs = cph;
}
int Programmer::getExHrs()
{
	return mExtraHrs;
}
double Programmer::getCostPerHrs()
{
	return mCostPerHrs;
}

void Programmer::display()
{
	Employee::display();
	cout << "Extra hrs done: " << getExHrs() << endl;
	cout << "Salary: " << calSal()<<endl;
}

double Programmer::calSal()
{
	return getBasic()+mExtraHrs*mCostPerHrs;
}

bool Programmer::writeToFile(ostream &out)
{
	if (Employee::writeToFile(out))
	{
		try {
			out << mExtraHrs << endl;
			out << mCostPerHrs << endl;
			return true;
		}
		catch (ostream::failure e) {
			return false;
		}
	}
	return false;

}

bool Programmer::readFromFile(istream &in)
{
	if (Employee::readFromFile(in)) {
		try {
			in >> mExtraHrs;
			in >> mCostPerHrs;
			return true;
		}
		catch (ostream::failure e) {
			return false;
		}
	}
	return false;
}

Programmer::~Programmer()
{
}