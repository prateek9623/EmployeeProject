#include"SalesMgr.h"
using namespace std;

char fileLoc[] = "database.txt";
vector <Employee*> emp;
fstream fileIO;

int main();

//void getFileData();
//void setFileData();
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
	int ch;
	int type;
	do
	{
	/*	empListDeleter();
		getFileData();
	*/	cout << endl << "---------- - MENU------------\n" << endl;
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
			break;
		default:
			cout << "Invalid Choice!!!";

		}
		//setFileData();
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
	emp.push_back(temp);
	//file.open(fileloc, ios::binary);
	return true;
}
bool deleteRecord(char empid[]) {
	for (int i = 0; i < emp.size(); i++) {
		if (strcmp(emp[i]->getId(), empid) == 0) {
			emp.erase(emp.begin() + i);
			return true;
		}
	}
	return false;
}
bool searchRecord(char empid[]) {
	for (int i = 0; i < emp.size(); i++) {
		if (strcmp(emp[i]->getId(), empid) == 0) {
			return true;
		}
	}
	return false;
}
void displayAll() {
	for (int i = 0; i < emp.size(); i++) {
		emp[i]->display();
	}
}
void display(int type)
{
	for (int i = 0; i < emp.size(); i++) {
		emp[i]->display();
		cout << endl;
	}
}
bool update(char empid[])
{
	for (int i = 0; i < emp.size(); i++) {
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
	for (int i = 0; i < emp.size(); i++) {
		for (int j = i + 1; j < emp.size(); j++) {
			if (strcmp(emp[i]->getId(), emp[j]->getId()) > 0)
				swap(emp[i], emp[j]);
		}
	}
}
void sortDatabyName()
{
	for (int i = 0; i < emp.size(); i++) {
		for (int j = i + 1; j < emp.size(); j++) {
			if (strcmp(emp[i]->getName(), emp[j]->getName()) > 0)
				swap(emp[i], emp[j]);
		}
	}
}
void sortDatabyType()
{
	for (int i = 0; i < emp.size(); i++) {
		for (int j = i + 1; j < emp.size(); j++) {
			if ((typeid(*emp[i]) == typeid(Programmer) && typeid(*emp[j]) == typeid(Admin)) || (typeid(*emp[i]) == typeid(SalesMgr) && typeid(*emp[j]) == typeid(Admin)))
				swap(emp[i], emp[j]);
			else if (typeid(*emp[i]) == typeid(SalesMgr) && typeid(*emp[j]) == typeid(Programmer))
				swap(emp[i], emp[j]);
		}
	}
}

void empListDeleter()
{
	for (int i = 0; i < emp.size(); i++)
		delete emp[i];

	emp.clear();
}

//void getFileData()
//{
//	fileIO.open(fileLoc, ios::in|ios::binary);
//	while (!fileIO.eof())
//	{
//		Employee *e;
//		fileIO.read((char*)e, sizeof(Employee));
//	}
//	fileIO.close();
//}
//
//void setFileData()
//{
//	fileIO.open(fileLoc, ios::out|ios::trunc|ios::binary);
//	for (int i = 0; i <emp.size(); i++)
//	{
//		if(strcmp("class Programmer",typeid(*emp[i]).name())==0)
//			fileIO.write((char*)emp[i], sizeof(Programmer));
//		else if (strcmp("class Admin", typeid(*emp[i]).name()) == 0)
//			fileIO.write((char*)emp[i], sizeof(Admin));
//		else if (strcmp("class SalesMgr", typeid(*emp[i]).name()) == 0)
//			fileIO.write((char*)emp[i], sizeof(SalesMgr));
//	}
//	fileIO.close();
//}