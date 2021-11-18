/****************************************************/
/*
��C++ʵ��
����汾
Visual Studio Community 2017 ����汾�У���Ȼ��Ҫ��ģ��ʵ�ֺͶ��嶼д��ͬһ��ͷ�ļ��С�
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
�γ�Ҫ��������Ļ�������
1. ���Ĵ���������
2. ���нڵ������
3. ���нڵ�������ɾ��
4. ���нڵ�ı���
*/
template<class T>
class MyTree {
public:
	MyTree();															// ����
	~MyTree();															// ����
	TreeNode<T>* SearchNode(int nodeIndex);								// ��������Ѱ�ҽڵ�
	bool AddNode(int nodeIndex, int direction, TreeNode<T>* pNode);		// ��ӽڵ�
	bool DeleteNode(int nodeIndex, TreeNode<T>* pNode);					// ɾ���ڵ�
	//void TreeTraverse();												// �����ڵ�
	void TreeTraversePreOrder();										// ǰ�����
	void TreeTraverseInOrder();											// �������
	void TreeTraversePostOrder();										// �������
private:
	TreeNode<T>* m_pTree;
	int m_iSize;
	//bool isIndexOutofBound(int nodeIndex);							// �±��Ƿ�Խ��
	//bool isNodeNull(int nodeIndex);									// �ڵ��Ƿ�Ϊ��
};

template<class T>
MyTree<T>::MyTree() {
	m_pTree = new TreeNode<T>();
}

template<class T>
MyTree<T>::~MyTree() {
	// ����ʽ�洢�ṹ�У���������һ��������Ҫɾ�����ڵ㡣
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

	pNode->pParent = nodeAim;// ָ�����ڵ㡣

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