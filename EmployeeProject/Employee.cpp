#include "Employee.h"

Employee::Employee(const char* id, double basic, const char *name, const char *addr)
{
	mEid = id;
	mBasic = basic;
	mName = name;
	mAddress = addr;
}

Employee::Employee()
{
}

void Employee::setBasic(double basic)
{
	mBasic = basic;
}
double Employee::getBasic()
{
	return mBasic;
}

const char* Employee::getId()
{
	return mEid.c_str();
}

void Employee::setName(const char *name)
{
	mName = name;
}
const char * Employee::getName()
{
	return mName.c_str();
}

void Employee::setAddr(const char *addr)
{
	mAddress = addr;
}
const char * Employee::getAddr()
{
	return mAddress.c_str();
}

void Employee::display()
{
	cout << "Employee id: " << getId() << endl;
	cout << "Employee name: " << getName() << endl;
	cout << "Employee Address: " << getAddr() << endl;
}

void Employee::update()
{
	double basic;
	string empaddr;
	cout << "Enter Employee basic salary::";
	cin >> basic;
	cout << "Enter Employee address::";
	getline(cin,empaddr);
	setAddr(empaddr.c_str());
	setBasic(basic);
}

bool Employee::writeToFile(ostream &out)
{
	try {
		out << mEid << endl;
		out << mName << endl;
		out << mAddress << endl;
		out << mBasic << endl;
		return true;
	}
	catch (ostream::failure e) {
		return false;
	}
}

bool Employee::readFromFile(istream &in)
{
	try {
		getline(in, mEid);
		getline(in, mName);
		getline(in, mAddress);
		in >> mBasic;
		return true;
	}
	catch (ostream::failure e) {
		return false;
	}
}

Employee::~Employee()
{
}

void Employee::setId(string id)
{
	mEid = id;
}
