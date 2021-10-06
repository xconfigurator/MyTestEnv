#pragma once
#define _CRT_SECURE_NO_WARNINGS
class DataRec {
private:
	char* name;
	char* streetAddress;
	char* city;
	char* state;
	char* zip;
public:
	DataRec();
	DataRec(char* n, char* st, char* cty, char* sta, char* zp);
	~DataRec();
	virtual void Print();
protected:
	char* StrSave(char* s);
};

class Student : virtual public DataRec {
private:
	char* major;
	int idNumber;
	int level;
public:
	Student(char* n, char* st, char* cty, char* sta, char* zp, char* m, int id, int lv)
		: DataRec(n, st, cty, sta, zp), idNumber(id), major(StrSave(m)), level(lv) {}
	Student(char* m, int id, int lv) : idNumber(id), major(StrSave(m)), level(lv) {}
	~Student() {
		delete major;
	}
	void Print();
protected:
	void Disp();
};


class Staff : virtual public DataRec {
private:
	char* dept;
	float hourlyWage;
public:
	Staff(char* n, char* st, char* cty, char* sta, char* zp, char* dp, float hrwg)
		: DataRec(n, st, cty, sta, zp), dept(StrSave(dp)), hourlyWage(hrwg) {}
	Staff(char* dp, float hrwg) : dept(StrSave(dp)), hourlyWage(hrwg) {}
	~Staff() { delete dept; }
	void Print();
protected:
	void Disp();
};

class Professor : public Staff {
private:
	float salary;
public:
	Professor(char* n, char* st, char* cty, char* sta, char* zp, char* dp, float sal) : DataRec(n, st, cty, sta, zp), Staff(dp, 0), salary(sal) {}
	void Print();
};

class StudentStaff : public Student, public Staff {
public:
	StudentStaff(char* n, char* st, char* cty, char* sta, char* zp, char* m, int id, int lv, char* dp, float hrwg) 
		: DataRec(n, st, cty, sta, zp), Student(m, id, lv), Staff(dp, hrwg) {}
	void Print();
};