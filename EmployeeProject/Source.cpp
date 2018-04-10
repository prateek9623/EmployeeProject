#include"SalesMgr.h"
#include"LinkedList.h"
using namespace std;

char SalesMgrDB[] = "SalesMgr.dat";
char ProgrammerDB[] = "Programmer.dat";
char AdminDB[] = "Admin.dat";
char EmpCountDB[] = "EmpCount.txt";
LinkedList <Employee*> emp;
fstream fileIO1;
fstream fileIO2;
fstream fileIO3;

void getFileData();
void setFileData();
bool insertRecord(int);
bool deleteRecord(char[]);
bool searchRecord(char[]);
void displayAll();
void display(int);
bool update(char[]);
void sortDatabyId();
void sortDatabyName();
void sortDatabyType();
void empListDeleter();

int main()
{
	getFileData();
	int ch;
	int type;
	do
	{
		//empListDeleter();
		cout << endl << "---------- - MENU------------\n" << endl;
		cout << "1.	Insert Record (Admin / Programmer / SalesMgr)" << endl;
		cout << "2.	Delete Record" << endl;
		cout << "3.	Search Employee" << endl;
		cout << "4.	Display All Records" << endl;
		cout << "5.	Display specific Records" << endl;
		cout << "6.	Update specific employee details by id" << endl;
		cout << "7.	Sort Data by Id" << endl;
		cout << "8.	Sort Data by Name" << endl;
		cout << "9.	Sort Data by Type" << endl;
		cout << "10.	To Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case 1:
			cout << "Enter employee designation(1.Admin/ 2.Programmer/ 3.Sales Manager)::";
			cin >> type;
			if (type < 0 && type>3) {
				cout << "Wrong Choice";
			}
			else {
				insertRecord(type);
				cout << "Record updated";
			}
			break;
		case 2:
			char empid[10];
			cout << "Enter employee id::";
			cin >> empid;
			if (deleteRecord(empid))
				cout << "Record deleted";
			else
				cout << "Record not found";
			break;
		case 3:
			//char empid[10];
			cout << "Enter employee id::";
			cin >> empid;
			if (!searchRecord(empid)) {
				cout << "Record not found";
			}
			else {
				cout << "Record found";
			}
			break;
		case 4:
			displayAll();
			break;
		case 5:
			cout << "Enter 1.Admin, 2.Programmer, 3. SalesMgr";
			cin >> type;
			display(type);
			break;
		case 6:
			cout << "Enter Employee id to update::";
			cin >> empid;
			if (searchRecord(empid)) {
				if (update(empid))
					cout << "Record Updated";
				else
					cout << "Something went wrong!!";
			}
			else
				cout << "Record not Found";
			break;
		case 7:
			cout << "Sorting data by id" << endl;
			sortDatabyId();
			cout << "sorting done";
			break;
		case 8:
			cout << "Sorting by Name" << endl;
			sortDatabyName();
			break;
		case 9:
			cout << "Sorting by Type" << endl;
			sortDatabyType();
			break;
		case 10:
			setFileData();
			break;
		default:
			cout << "Invalid Choice!!!";

		}
	} while (ch != 10);

}

bool insertRecord(int classType)
{
	Employee *temp;
	char empid[10], empname[20], empaddr[50];
	int basic;
	cout << "Enter Employee id::";
	cin >> empid;
	cout << "Enter Employee name::";
	cin >> empname;
	cout << "Enter Employee basic salary::";
	cin >> basic;
	cout << "Enter Employee address::";
	cin >> empaddr;
	if (classType == 1) {
		int empIncentive;
		cout << "Enter Employee Incentive::";
		cin >> empIncentive;
		temp = new Admin(empid, basic, empname, empaddr, empIncentive);
	}
	else if (classType == 2) {
		int extraHrs;
		double costPerHrs;
		cout << "Enter Employee Extra hours done::";
		cin >> extraHrs;
		cout << "Enter Employee cost per hours";
		cin >> costPerHrs;
		temp = new Programmer(empid, basic, empname, empaddr, extraHrs, costPerHrs);
	}
	else if (classType == 3) {
		double commision;
		int sales;
		cout << "Enter commsion to be recieved::";
		cin >> commision;
		cout << "Enter sales done";
		cin >> sales;
		temp = new SalesMgr(empid, basic, empname, empaddr, sales, commision);
	}
	else
		return false;
	emp.insert(temp);
	//file.open(fileloc, ios::binary);
	return true;
}
bool deleteRecord(char empid[]) {
	for (int i = 0; i < emp.getSize(); i++) {
		if (strcmp(emp[i]->getId(), empid) == 0) {
			return emp.remove(i);;
		}
	}
	return false;
}
bool searchRecord(char empid[]) {
	for (int i = 0; i < emp.getSize(); i++) {
		if (strcmp(emp[i]->getId(), empid) == 0) {
			return true;
		}
	}
	return false;
}
void displayAll() {
	for (int i = 0; i < emp.getSize(); i++) {
		emp[i]->display();
		cout << endl;
	}
}
void display(int type)
{
	for (int i = 0; i < emp.getSize(); i++) {
		emp[i]->display();
		cout << endl;
	}
}
bool update(char empid[])
{
	for (int i = 0; i < emp.getSize(); i++) {
		if (strcmp(emp[i]->getId(), empid) == 0)
		{
			emp[i]->update();
			return true;
		}
	}
	return false;
}
void sortDatabyId()
{
	for (int i = 0; i < emp.getSize(); i++) {
		for (int j = i + 1; j < emp.getSize(); j++) {
			if (strcmp(emp[i]->getId(), emp[j]->getId()) > 0)
				swap(emp[i], emp[j]);
		}
	}
}
void sortDatabyName()
{
	for (int i = 0; i < emp.getSize(); i++) {
		for (int j = i + 1; j < emp.getSize(); j++) {
			if (strcmp(emp[i]->getName(), emp[j]->getName()) > 0)
				swap(emp[i], emp[j]);
		}
	}
}
void sortDatabyType()
{
	for (int i = 0; i < emp.getSize(); i++) {
		for (int j = i + 1; j < emp.getSize(); j++) {
			if ((typeid(*emp[i]) == typeid(Programmer) && typeid(*emp[j]) == typeid(Admin)) || (typeid(*emp[i]) == typeid(SalesMgr) && typeid(*emp[j]) == typeid(Admin)))
				swap(emp[i], emp[j]);
			else if (typeid(*emp[i]) == typeid(SalesMgr) && typeid(*emp[j]) == typeid(Programmer))
				swap(emp[i], emp[j]);
		}
	}
}

void empListDeleter()
{
	emp.deleteList();
}
//NOT WORKING NEED TO CHECK WITH VINAYAK SIR
//void getFileData()
//{
//	int salesMgrCount = 0;
//	int programmerCount = 0;
//	int adminCount = 0;
//	ifstream fileIO4;
//	fileIO4.open(EmpCountDB);
//	fileIO4 >> salesMgrCount >>programmerCount >>adminCount;
//	fileIO4.close();
//	fileIO1.open(SalesMgrDB, ios::in);
//	if (fileIO1.is_open())
//	{
//		SalesMgr *temp = new SalesMgr;
//		int count = 0;
//		//while (fileIO1.read((char*)temp, sizeof(SalesMgr))&&count<salesMgrCount)
//		{
//			//fileIO1.read((char*)temp, sizeof(SalesMgr));
//			emp.insert(temp);
//			count++;
//		}
//		fileIO1.close();
//	}
//	fileIO2.open(ProgrammerDB, ios::in | ios::binary);
//	if (fileIO2.is_open())
//	{
//		Programmer *temp = new Programmer;
//		int count = 0;
//		//while (fileIO2.read((char*)temp, sizeof(Programmer)) && count < programmerCount)
//		{
//			//fileIO2.read((char*)temp, sizeof(Programmer));
//			emp.insert(temp);
//			count++;
//		}
//		fileIO2.close();
//	}
//	fileIO3.open(AdminDB, ios::in | ios::binary);
//	if (fileIO3.is_open())
//	{
//		Admin *temp = new Admin;
//		int count = 0;
//		//while (fileIO3.read((char*)temp, sizeof(Admin))&& count < adminCount)
//		{
//			//fileIO3.read((char*)temp, sizeof(Admin));
//			emp.insert(temp);
//			count++;
//		}
//		fileIO3.close();
//	}
//}
//
//void setFileData()
//{
//	int salesMgrCount = 0;
//	int programmerCount = 0;
//	int adminCount = 0;
//	remove(ProgrammerDB);
//	remove(SalesMgrDB);
//	remove(AdminDB);
//	for (int i = 0; i <emp.getSize(); i++)
//	{
//		if (typeid(*emp[i]) == typeid(Programmer))
//		{
//			fileIO1.open(ProgrammerDB, ios::out | ios::app);
//			fileIO1.write((char*)emp[i], sizeof(Programmer));
//			fileIO1.close();
//			programmerCount++;
//		}
//		else if (typeid(*emp[i]) == typeid(Admin))
//		{
//			fileIO2.open(AdminDB, ios::out | ios::app);
//			fileIO2.write((char*)emp[i], sizeof(Admin));
//			fileIO2.close();
//			adminCount++;
//		}
//		else if (typeid(*emp[i]) == typeid(SalesMgr))
//		{
//			fileIO3.open(SalesMgrDB, ios::out | ios::app);
//			fileIO3.write((char*)emp[i], sizeof(SalesMgr));
//			fileIO3.close();
//			salesMgrCount++;
//		}
//	}
//	ofstream fileIO4;
//	fileIO4.open(EmpCountDB);
//	fileIO4 << salesMgrCount <<endl<< programmerCount << endl << adminCount;
//	fileIO4.close();
//}
void setFileData()
{
	int salesMgrCount = 0;
	int programmerCount = 0;
	int adminCount = 0;
	remove(ProgrammerDB);
	remove(SalesMgrDB);
	remove(AdminDB);
	for (int i = 0; i <emp.getSize(); i++)
	{
		if (typeid(*emp[i]) == typeid(Programmer))
		{
			fileIO1.open(ProgrammerDB, ios::out | ios::app);
			emp[i]->writeToFile(fileIO1);
			fileIO1.close();
			programmerCount++;
		}
		else if (typeid(*emp[i]) == typeid(Admin))
		{
			fileIO2.open(AdminDB, ios::out | ios::app);
			emp[i]->writeToFile(fileIO2);
			fileIO2.close();
			adminCount++;
		}
		else if (typeid(*emp[i]) == typeid(SalesMgr))
		{
			fileIO3.open(SalesMgrDB, ios::out | ios::app);
			emp[i]->writeToFile(fileIO3);
			fileIO3.close();
			salesMgrCount++;
		}
	}
	ofstream fileIO4;
	fileIO4.open(EmpCountDB);
	fileIO4 << salesMgrCount <<endl<< programmerCount << endl << adminCount;
	fileIO4.close();
}
void getFileData()
{
	int salesMgrCount = 0;
	int programmerCount = 0;
	int adminCount = 0;
	ifstream fileIO4;
	fileIO4.open(EmpCountDB);
	fileIO4 >> salesMgrCount >>programmerCount >>adminCount;
	fileIO4.close();
	fileIO1.open(SalesMgrDB, ios::in);
	if (fileIO1.is_open())
	{
		Employee *temp = new SalesMgr;
		int count = 0;
		while (!fileIO1.eof()&&count<salesMgrCount)
		{
			temp->readFromFile(fileIO1);
			emp.insert(temp);
			count++;
		}
		fileIO1.close();
	}
	fileIO2.open(ProgrammerDB, ios::in);
	if (fileIO2.is_open())
	{
		Employee *temp = new Programmer;
		int count = 0;
		while (!fileIO2.eof() && count < programmerCount)
		{
			temp->readFromFile(fileIO2);
			emp.insert(temp);
			count++;
		}
		fileIO2.close();
	}
	fileIO3.open(AdminDB, ios::in);
	if (fileIO3.is_open())
	{
		Employee *temp = new Admin;
		int count = 0;
		while (!fileIO3.eof()&& count < adminCount)
		{
			temp->readFromFile(fileIO3);
			emp.insert(temp);
			count++;
		}
		fileIO3.close();
	}
}