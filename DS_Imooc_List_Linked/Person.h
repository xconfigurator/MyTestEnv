/****************************************************/
/*
链表C++实现
使用类模板
演示通讯录实例
Visual Studio 2015，这个类模板还是只能写在.h文件中。
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
	// 注意到这个函数并不属于Person类。
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
	Person& operator=(const Person& person) {// 重载赋值运算符
		this->name = person.name;
		this->phone = person.phone;
		return *this;
	}
public:
	string name;
	string phone;
};

#endif
