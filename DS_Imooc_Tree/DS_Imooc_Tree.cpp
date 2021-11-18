#include <iostream>
#include "MyTree.h"
#define LEFT_CHILD 0
#define RIGHT_CHILD 1
using namespace std;


/*

e.g. int tree[n] 3 5 8 2 6 9 7
			3[0]
	5[1]            8[2]
2[3]    6[4]    9[5]    7[6]

*/
int main() {
	int root = 3;
	MyTree* pTree = new MyTree(10, &root);
	int n1 = 5;
	pTree->AddNode(0, LEFT_CHILD, &n1);
	int n2 = 8;
	pTree->AddNode(0, RIGHT_CHILD, &n2);

	int n3 = 2;
	pTree->AddNode(1, LEFT_CHILD, &n3);
	int n4 = 6;
	pTree->AddNode(1, RIGHT_CHILD, &n4);

	int n5 = 9;
	pTree->AddNode(2, LEFT_CHILD, &n5);
	int n6 = 7;
	pTree->AddNode(2, RIGHT_CHILD, &n6);

	pTree->TreeTraverse();


	cout << "###################" << endl;
	int idx = 5;
	int* p = pTree->SearchNode(idx);
	cout << "node" << idx << " = " << *p << endl;


	cout << "###################" << endl;
	idx = 5;
	int nodeValue = 0;
	pTree->DeleteNode(idx, &nodeValue);
	cout << "node" << idx << "已被删除，其值是 " << nodeValue << endl;
	pTree->TreeTraverse();

	delete pTree;
	return 0;
}