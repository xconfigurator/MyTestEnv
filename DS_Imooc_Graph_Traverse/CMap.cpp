#include "CMap.h"
#include <iostream>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;									// 一开始，图中一个顶点都没有。
	m_pNodeArray = new Node[m_iCapacity];				// 顶点的数组
	m_pMatrix = new int[m_iCapacity * m_iCapacity];		// 邻接矩阵的数组
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
	m_pBfsQueue = new queue<int>();						// BFS需要用到的队列
}

CMap::~CMap()
{
	if (NULL != m_pNodeArray) delete[] m_pNodeArray;
	if (NULL != m_pMatrix) delete[] m_pMatrix;
	if (NULL != m_pBfsQueue) delete m_pBfsQueue;
}

bool CMap::addNode(Node* pNode)
{
	if (NULL == pNode) return false;

	m_pNodeArray[m_iNodeCount++].m_cData = pNode->m_cData;// 在Node对象中并没有定义顶点的索引。本方案中索引就是m_pNodeArray的下标。
	return true;
}

void CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity) return false;
	if (col < 0 || col >= m_iCapacity) return false;
	
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity) return false;
	if (col < 0 || col >= m_iCapacity) return false;

	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

void CMap::printMatrix()
{
	// 表头
	cout << "  ";
	for (int i = 0; i < m_iCapacity; i++) {
		cout << m_pNodeArray[i].m_cData << " ";
	}
	cout << endl;

	// 打印矩阵
	for (int i = 0; i < m_iCapacity; i++) {
		// 第一列
		cout << m_pNodeArray[i].m_cData << " ";
		for (int j = 0; j < m_iCapacity; j++) {
			cout << m_pMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
}

// DFS
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	
	// 根
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// 邻接点（查邻接矩阵）
	for (int i = 0; i < m_iCapacity; i++) {
		getValueFromMatrix(nodeIndex, i, value);
		if (value != 0) {
			if (m_pNodeArray[i].m_bIsVisited) {
				continue;
			}
			depthFirstTraverse(i);// DFS
		}
	}
}

// BFS
void CMap::breadthFirstTraverse(int nodeIndex)
{
	// 入队
	// 如果不想把Queue定义成成员变量，则可以考虑视频中使用的 breadthFirstTraverse中定义，在breadthFirstTraverseimpl中调用的模式。（个人感觉视频里介绍的这种方式更好！）
	// 这里为了跟浙大视频靠拢，采用定义成员变量Queue的方式
	m_pBfsQueue->push(nodeIndex);

	// 遍历队列
	int idx = 0;
	int value = 0;
	while (!m_pBfsQueue->empty()) {
		// 出队
		idx = m_pBfsQueue->front();
		m_pBfsQueue->pop();

		// 访问
		cout << m_pNodeArray[idx].m_cData << " ";
		m_pNodeArray[idx].m_bIsVisited = true;

		// 邻接点（查邻接矩阵）
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(idx, i, value);
			if (value != 0 && !m_pNodeArray[i].m_bIsVisited) {
				m_pBfsQueue->push(i);
			}
		}
	}

	// TODO 为啥不对 ??? !!!
}

bool CMap::getValueFromMatrix(int row, int col, int& val)
{
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	// TODO
}
