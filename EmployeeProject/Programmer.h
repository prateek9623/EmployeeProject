#pragma once
#include "Admin.h"
class Programmer :
	public Employee
{
	int mExtraHrs;
	double mCostPerHrs;
public:
	//base::const id, double basic, const char *name, const char *add derived:: int extraHrs, double costPerHrs.
	Programmer(const char*, double, const char *, const char *, int, double);
	void update();
	void setExHrs(int);
	void setCostPerHrs(int);
	int getExHrs();
	double getCostPerHrs();
	void display();
	double calSal();
	~Programmer();
};
