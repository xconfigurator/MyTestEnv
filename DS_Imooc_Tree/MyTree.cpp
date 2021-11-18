#include <iostream>
#include "MyTree.h"
using namespace std;

// ����
MyTree::MyTree(int size, int* pRoot) {
	m_pTree = new int[size];
	m_iSize = size;
	for (int i = 0; i < m_iSize; ++i) {
		m_pTree[i] = 0;
	}

	m_pTree[0] = *pRoot;// ��ʼ�����ڵ�
}

// ����
MyTree::~MyTree() {
	delete[] m_pTree;
	m_pTree = NULL;
}


// ��������Ѱ�ҽڵ�
int* MyTree::SearchNode(int nodeIndex) {
	if (isIndexOutofBound(nodeIndex)) {
		return NULL;
	}
	return &m_pTree[nodeIndex];
}


// ��ӽڵ�
bool MyTree::AddNode(int nodeIndex, int direction, int* pNode) {
	if (isIndexOutofBound(nodeIndex)) {
		return false;
	}
	if (isNodeNull(nodeIndex)) {
		return false;
	}

	// ���������
	if (0 == direction) {
		nodeIndex = 2 * nodeIndex + 1;
	}

	// ������Һ���
	if (1 == direction) {
		nodeIndex = 2 * nodeIndex + 2;
	}

	if (nodeIndex > m_iSize) {// �����ڵ��±��Ƿ�Ϸ�
		return false;
	}

	if (isIndexOutofBound(nodeIndex)) {
		return false;
	}

	if (!isNodeNull(nodeIndex)) {// ����Ѿ���ֵ�������ʧ��
		return false;
	}

	// ��ֵ
	m_pTree[nodeIndex] = *pNode;
	return true;
}


// ɾ���ڵ�
bool MyTree::DeleteNode(int nodeIndex, int* pNode) {
	if (isIndexOutofBound(nodeIndex)) {
		return false;
	}
	if (isNodeNull(nodeIndex)) {
		return false;
	}

	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}


// �����ڵ�
void MyTree::TreeTraverse() {
	for (int i = 0; i < m_iSize; ++i) {
		cout << m_pTree[i] << " ";
	}
	cout << endl;
}



// �ж��±��Ƿ�Խ��
bool MyTree::isIndexOutofBound(int nodeIndex) {
	bool flag = false;

	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
		flag = true;
	}

	return flag;
}

// �ڵ��Ƿ�ǿ�
bool MyTree::isNodeNull(int nodeIndex) {
	bool flag = false;

	if (m_pTree[nodeIndex] == 0) {// Լ�����0�ͱ�ʾ��
		flag = true;
	}

	return flag;
}