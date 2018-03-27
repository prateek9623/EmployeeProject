#include "Employee.h"

Employee::Employee(const char* id, double basic, const char *name, const char *addr)
{
	mEid = id;
	mBasic = basic;
	mName = name;
	mAddress = addr;
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
	char empaddr[50];
	cout << "Enter Employee basic salary::";
	cin >> basic;
	cout << "Enter Employee address::";
	cin >> empaddr;
	setAddr(empaddr);
	setBasic(basic);
}
Employee::~Employee()
{
}