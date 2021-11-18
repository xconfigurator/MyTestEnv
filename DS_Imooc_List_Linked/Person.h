/****************************************************/
/*
����C++ʵ��
ʹ����ģ��
��ʾͨѶ¼ʵ��
Visual Studio 2015�������ģ�廹��ֻ��д��.h�ļ��С�
@since 2016/12/22
@author liuyang
*/
/****************************************************/
#ifndef _PERSON_
#define _PERSON_
#include <iostream>
#include <string>
using namespace std;

class Person {
	// ע�⵽���������������Person�ࡣ
	friend ostream& operator<<(ostream& os, const Person& p) {// toString()
		os << "(name = " << p.name << ", phone=" << p.phone << ")" << endl;
		return os;
	}
public:
	bool operator==(const Person& p) {// equals()
		bool flag = true;

		if (this->name != p.name) {
			flag = false;
		}

		if (this->phone != p.phone) {
			flag = false;
		}

		return flag;
	}
	Person& operator=(const Person& person) {// ���ظ�ֵ�����
		this->name = person.name;
		this->phone = person.phone;
		return *this;
	}
public:
	string name;
	string phone;
};

#endif
