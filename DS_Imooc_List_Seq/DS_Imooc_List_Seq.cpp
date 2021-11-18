/*
@since 2016/12/18
@Author liuyang
顺序表(测试用例)
eg:3 5 7 2 9 1 8
编译环境：Visual Studio 2015 Community
*/
#include <iostream>
#include "SeqList.h"
using namespace std;

int main() {
	SeqList<int>* plist = new SeqList<int>(10);
	cout << "#初始化==================================" << endl;
	/*
	int e = 7;
	plist->ListInsert(0, &e);
	e = 5;
	plist->ListInsert(0, &e);
	*/

	// 初始化
	int data[] = { 3, 5, 7 , 2, 9, 1, 8 };
	for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
		plist->ListInsert(i, &data[i]);
	}
	cout << "长度 插入前 = " << plist->ListLength() << endl;
	int e = 8;
	plist->ListInsert(3, &e);// 任意位置插入
	plist->ListTraverse();
	cout << "长度 插入后 = " << plist->ListLength() << endl;

	cout << "#指定元素==================================" << endl;
	if (plist->GetElem(3, &e)) {
		cout << " plist->GetElem(3, &e) " << e << endl;
	}
	else {
		cout << " 该位置无元素。" << endl;
	}

	cout << "#定位元素==================================" << endl;
	e = 8;
	cout << "plist->LocateElem(&e) e = 8 idx = " << plist->LocateElem(&e) << endl;

	cout << "#前驱后继==================================" << endl;
	e = 8;
	int tmp = 0;
	plist->PriorElem(&e, &tmp);
	cout << "e = " << e << " 的前驱 = " << tmp << endl;
	plist->NextElem(&e, &tmp);
	cout << "e = " << e << " 的后继 = " << tmp << endl;

	cout << "#删除==================================" << endl;
	plist->ListDelete(3, &e);// 删除
	plist->ListTraverse();


	cout << "#清空==================================" << endl;
	cout << "清空前 plist->ListEmpty() = " << boolalpha << plist->ListEmpty() << endl;
	plist->ClearList();// 清空
	cout << "清空前 plist->ListEmpty() = " << boolalpha << plist->ListEmpty() << endl;
	plist->ListTraverse();

	cout << "#指定元素==================================" << endl;
	if (plist->GetElem(3, &e)) {
		cout << " plist->GetElem(3, &e) " << e << endl;
	}
	else {
		cout << " 该位置无元素。" << endl;
	}

	delete plist;
	plist = NULL;

	return 0;
}