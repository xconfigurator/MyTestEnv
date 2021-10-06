#include "school.h"
#include <iostream>
#include <string.h>

using namespace std;

DataRec::DataRec() {
	name = NULL;
	streetAddress = NULL;
	city = NULL;
	state = NULL;
	zip = NULL;
}

DataRec::DataRec(char* n, char* st, char* cty, char* sta, char* zp)
{
	name = StrSave(n);
	streetAddress = StrSave(st);
	city = StrSave(cty);
	state = StrSave(sta);
	zip = StrSave(zp);
}

DataRec::~DataRec()
{
	delete name;
	delete streetAddress;
	delete city;
	delete state;
	delete zip;
}

void DataRec::Print()
{
	cout << endl << endl
		<< name << endl
		<< streetAddress << endl
		<< city << ","
		<< state << " "
		<< zip << endl;
}

char* DataRec::StrSave(char* s)
{
	char* p;
	p = new char[strlen(s) + 1];
	strcpy(p, s);
	//return nullptr;
	return p;
}

void Student::Print()
{
	DataRec::Print();
	Disp();
}

void Student::Disp()
{
	cout << "major:" << major << endl;
	cout << "Id number:" << idNumber << endl;
	cout << "level:" << level << endl;
}

void Staff::Print()
{
	DataRec::Print();
	Disp();
}

void Staff::Disp()
{
	cout << "Department:" << dept << endl;
	cout << "hourly wage:" << hourlyWage << endl;
}

void Professor::Print()
{
	Staff::Print();
	cout << "Salary:" << salary << endl;
}

void StudentStaff::Print()
{
	DataRec::Print();
	Student::Disp();
	Staff::Disp();
}
