/*
@since 2016/12/18 update 2016/12/22
@Author liuyang
顺序表(测试用例)
eg:3 5 7 2 9 1 8
编译环境：Visual Studio 2015 Community
*/
#include <iostream>
#include "LinkedList.h"
#include "Person.h"
using namespace std;

int menu() {
	// 显示功能菜单
	cout << "############" << endl;
	cout << "##功能菜单##" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;
	cout << "############" << endl;

	cout << "请输入：";
	int order = 0;
	cin >> order;
	return order;
}

void createPerson(LinkedList<Person>* plist) {
	string name = "";
	string phone = "";
	cout << endl;
	cout << "请输入姓名："; cin >> name;
	cout << "请输入电话号码："; cin >> phone;

	Node<Person> node;
	Person p;
	p.name = name;
	p.phone = phone;
	node.data = p;

	plist->ListInsertTail(&node);
}

void deletePerson(LinkedList<Person>* plist) {
	string name = "";
	string phone = "";
	cout << endl;
	cout << "请输入姓名："; cin >> name;
	cout << "请输入电话号码："; cin >> phone;

	Node<Person> node;
	Person p;
	p.name = name;
	p.phone = phone;
	node.data = p;

	int loc = plist->LocateElem(&node);
	if (plist->ListDelete(loc, &node)) {
		cout << p << "已被删除" << endl;
	}
	else {
		cout << p << "未被删除" << endl;
	}

}

void viewPersonList(LinkedList<Person>* plist) {
	plist->ListTraverse();
}


int main() {
	LinkedList<Person>* plist = new LinkedList<Person>();

	// 菜单外壳 begin
	int userOrder = 0;
	while (userOrder != 4) {
		userOrder = menu();
		switch (userOrder) {
		case 1:
			cout << "用户指令 1.新建联系人 " << endl;
			createPerson(plist);
			break;
		case 2:
			cout << "用户指令 2.删除联系人 " << endl;
			deletePerson(plist);
			break;
		case 3:
			cout << "用户指令 3.浏览通讯录 " << endl;
			viewPersonList(plist);
			break;
		case 4:
			cout << "用户指令 4.退出通讯录 " << endl;
			break;
		}
	}
	// 菜单外壳 end

	delete plist;
	plist = NULL;

	return 0;
}