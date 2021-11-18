#include <iostream>
#include "MyTree.h"
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
using namespace std;

/*
			3[0]
	5[1]            8[2]
2[3]    6[4]    9[5]    7[6]

*/

int main() {

	MyTree<int>* tree = new MyTree<int>();

	// 形成Tree
	TreeNode<int>* node1 = new TreeNode<int>();
	node1->index = 1;
	node1->data = 5;
	tree->AddNode(0, DIRECTION_LEFT, node1);

	TreeNode<int>* node2 = new TreeNode<int>();
	node2->index = 2;
	node2->data = 8;
	tree->AddNode(0, DIRECTION_RIGHT, node2);


	TreeNode<int>* node3 = new TreeNode<int>();
	node3->index = 3;
	node3->data = 2;
	tree->AddNode(1, DIRECTION_LEFT, node3);

	TreeNode<int>* node4 = new TreeNode<int>();
	node4->index = 4;
	node4->data = 6;
	tree->AddNode(1, DIRECTION_RIGHT, node4);


	cout << "#debuging... =>" << tree->SearchNode(0) << endl;
	cout << "#debuging... =>" << tree->SearchNode(1) << endl;
	cout << "#debuging... =>" << tree->SearchNode(2) << endl;

	TreeNode<int>* node5 = new TreeNode<int>();
	node5->index = 5;
	node5->data = 9;
	tree->AddNode(2, DIRECTION_LEFT, node5);

	TreeNode<int>* node6 = new TreeNode<int>();
	node6->index = 6;
	node6->data = 7;
	tree->AddNode(2, DIRECTION_RIGHT, node6);

	cout << "#TreeTraversePreOrder()" << endl;
	tree->TreeTraversePreOrder();
	cout << "#TreeTraverseInOrder()" << endl;
	tree->TreeTraverseInOrder();
	cout << "#TreeTraversePostOrder()" << endl;
	tree->TreeTraversePostOrder();

	cout << endl;
	TreeNode<int>* tmp = new TreeNode<int>;
	tree->DeleteNode(6, NULL);
	tree->DeleteNode(5, NULL);
	//cout << *tmp << endl;
	cout << "#TreeTraverseInOrder()" << endl;
	tree->TreeTraverseInOrder();


	delete tree;// 调用MyTree的析构函数

	system("pause");
	return 0;
}