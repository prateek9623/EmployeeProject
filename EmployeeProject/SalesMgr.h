#pragma once
#include "Programmer.h"
class SalesMgr :
	public Employee
{
	int mTarget=20;
	double mCommision;
	int mSales=0;
public:
	SalesMgr();
	//Base:const char id, double basic, char *name, char *addr Derived: int target, double commision
	SalesMgr(const char*, double, const char *, const char *, int, double);
	void setCommision(double);
	void setSales(int);
	double getCommision();
	int getSales();
	void display();
	double calSal();
	void update();

	//bool virtual writeToFile(ostream);
	//bool virtual readFromFile(istream);
	
	~SalesMgr();
};
