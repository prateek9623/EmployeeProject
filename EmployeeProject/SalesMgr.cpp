#include "SalesMgr.h"


SalesMgr::SalesMgr(const char* id, double basic,const char *name, const char *addr, int sales, double commision) :Employee(id, basic, name, addr)
{
	mSales = sales;
	mCommision = commision;
}

void SalesMgr::setCommision(double commision)
{
	mCommision = commision;
}
double SalesMgr::getCommision()
{
	return mCommision;
}

void SalesMgr::setSales(int sales)
{
	mSales = sales;
}

int SalesMgr::getSales()
{
	return mSales;
}

void SalesMgr::display()
{
	Employee::display();
	cout << "Target:: " << mTarget<<endl;
	cout << "Salesdone::" << mSales<<endl;
	cout << "Salary::" << calSal();
}

double SalesMgr::calSal()
{
	return getBasic()+(mTarget>mSales?0:mCommision);
}

void SalesMgr::update()
{
	double commision;
	int sales;
	cout << "Enter commsion to be recieved::";
	cin >> commision;
	cout << "Enter sales done";
	cin >> sales;
	setCommision(commision);
	setSales(sales);
}

SalesMgr::~SalesMgr()
{
}
