/****************************************************/
/*
树C++实现
数组版本
Visual Studio Community 2017 这个版本中，仍然需要把模板实现和定义都写在同一个头文件中。
@since 2017/9/15
@author liuyang
@update
*/
/****************************************************/
#pragma once
#include "TreeNode.h"
#include <iostream>
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
using namespace std;

/*
课程要求：完成树的基本操作
1. 树的创建和销毁
2. 树中节点的搜索
3. 树中节点的添加与删除
4. 树中节点的遍历
*/
template<class T>
class MyTree {
public:
	MyTree();															// 创建
	~MyTree();															// 销毁
	TreeNode<T>* SearchNode(int nodeIndex);								// 根据索引寻找节点
	bool AddNode(int nodeIndex, int direction, TreeNode<T>* pNode);		// 添加节点
	bool DeleteNode(int nodeIndex, TreeNode<T>* pNode);					// 删除节点
	//void TreeTraverse();												// 遍历节点
	void TreeTraversePreOrder();										// 前序遍历
	void TreeTraverseInOrder();											// 中序遍历
	void TreeTraversePostOrder();										// 后序遍历
private:
	TreeNode<T>* m_pTree;
	int m_iSize;
	//bool isIndexOutofBound(int nodeIndex);							// 下标是否越界
	//bool isNodeNull(int nodeIndex);									// 节点是否为空
};

template<class T>
MyTree<T>::MyTree() {
	m_pTree = new TreeNode<T>();
}

template<class T>
MyTree<T>::~MyTree() {
	// 在链式存储结构中，销毁整个一颗树就是要删除根节点。
	m_pTree->DeleteNode();
}

template<class T>
TreeNode<T>* MyTree<T>::SearchNode(int nodeIndex) {
	return m_pTree->SearchNode(nodeIndex);
}

template<class T>
bool MyTree<T>::AddNode(int nodeIndex, int direction, TreeNode<T>* pNode) {
	TreeNode<T>* nodeAim = SearchNode(nodeIndex);

	if (nodeAim == NULL) {
		return false;
	}

	TreeNode<T>* node = new TreeNode<T>();
	node->index = pNode->index;
	node->data = pNode->data;

	if (direction == DIRECTION_LEFT) {
		nodeAim->pLeft = node;
	}

	if (direction == DIRECTION_RIGHT) {
		nodeAim->pRight = node;
	}

	pNode->pParent = nodeAim;// 指定父节点。

	return true;
}

template<class T>
bool MyTree<T>::DeleteNode(int nodeIndex, TreeNode<T>* pNode) {
	TreeNode<T>* temp = SearchNode(nodeIndex);

	if (temp == NULL) {
		return false;
	}

	if (pNode) {// if (pNode != NULL)
		pNode->data = temp->data;
		pNode->index = temp->index;
		pNode->pLeft = temp->pLeft;
		pNode->pRight = temp->pRight;
	}

	temp->DeleteNode();
}

template<class T>
void MyTree<T>::TreeTraversePreOrder() {
	m_pTree->TreeTraversePreOrder();
}

template<class T>
void MyTree<T>::TreeTraverseInOrder() {
	m_pTree->TreeTraverseInOrder();
}

template<class T>
void MyTree<T>::TreeTraversePostOrder() {
	m_pTree->TreeTraversePostOrder();
}