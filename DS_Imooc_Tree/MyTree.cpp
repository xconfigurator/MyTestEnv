#include <iostream>
#include "MyTree.h"
using namespace std;

// 创建
MyTree::MyTree(int size, int* pRoot) {
	m_pTree = new int[size];
	m_iSize = size;
	for (int i = 0; i < m_iSize; ++i) {
		m_pTree[i] = 0;
	}

	m_pTree[0] = *pRoot;// 初始化根节点
}

// 销毁
MyTree::~MyTree() {
	delete[] m_pTree;
	m_pTree = NULL;
}


// 根据索引寻找节点
int* MyTree::SearchNode(int nodeIndex) {
	if (isIndexOutofBound(nodeIndex)) {
		return NULL;
	}
	return &m_pTree[nodeIndex];
}


// 添加节点
bool MyTree::AddNode(int nodeIndex, int direction, int* pNode) {
	if (isIndexOutofBound(nodeIndex)) {
		return false;
	}
	if (isNodeNull(nodeIndex)) {
		return false;
	}

	// 如果是左孩子
	if (0 == direction) {
		nodeIndex = 2 * nodeIndex + 1;
	}

	// 如果是右孩子
	if (1 == direction) {
		nodeIndex = 2 * nodeIndex + 2;
	}

	if (nodeIndex > m_iSize) {// 新增节点下标是否合法
		return false;
	}

	if (isIndexOutofBound(nodeIndex)) {
		return false;
	}

	if (!isNodeNull(nodeIndex)) {// 如果已经有值，则插入失败
		return false;
	}

	// 赋值
	m_pTree[nodeIndex] = *pNode;
	return true;
}


// 删除节点
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


// 遍历节点
void MyTree::TreeTraverse() {
	for (int i = 0; i < m_iSize; ++i) {
		cout << m_pTree[i] << " ";
	}
	cout << endl;
}



// 判断下标是否越界
bool MyTree::isIndexOutofBound(int nodeIndex) {
	bool flag = false;

	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
		flag = true;
	}

	return flag;
}

// 节点是否非空
bool MyTree::isNodeNull(int nodeIndex) {
	bool flag = false;

	if (m_pTree[nodeIndex] == 0) {// 约定存放0就表示空
		flag = true;
	}

	return flag;
}