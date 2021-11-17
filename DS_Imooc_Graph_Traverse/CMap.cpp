#include "CMap.h"
#include <iostream>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;									// һ��ʼ��ͼ��һ�����㶼û�С�
	m_pNodeArray = new Node[m_iCapacity];				// ���������
	m_pMatrix = new int[m_iCapacity * m_iCapacity];		// �ڽӾ��������
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
	//m_pBfsQueue = new queue<int>();						// BFS��Ҫ�õ��Ķ���
}

CMap::~CMap()
{
	if (NULL != m_pNodeArray) delete[] m_pNodeArray;
	if (NULL != m_pMatrix) delete[] m_pMatrix;
	//if (NULL != m_pBfsQueue) delete m_pBfsQueue;
}

bool CMap::addNode(Node* pNode)
{
	if (NULL == pNode) return false;

	m_pNodeArray[m_iNodeCount++].m_cData = pNode->m_cData;// ��Node�����в�û�ж��嶥�������������������������m_pNodeArray���±ꡣ
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
	// ��ͷ
	cout << "  ";
	for (int i = 0; i < m_iCapacity; i++) {
		cout << m_pNodeArray[i].m_cData << " ";
	}
	cout << endl;

	// ��ӡ����
	for (int i = 0; i < m_iCapacity; i++) {
		// ��һ��
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
	
	// ��
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// �ڽӵ㣨���ڽӾ���
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

// BFS��BFSʵ�����������ݽṹ��Ƶ���ܷ�����
void CMap::breadthFirstTraverse(int nodeIndex)
{
	queue<int> q;// ���ǵݹ麯��������ʹ�þֲ����С�

	// ����
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// ���
	// ����Ϊ�˸������Ƶ��£�����ö����Ա����Queue�ķ�ʽ, ��Ƶ�в���������һ�ֽ��ܷ�ʽ��������Ϊ�Ƚ����ң��Ͳ�Ҫ�ٿ��ˡ�
	//m_pBfsQueue->push(nodeIndex);
	q.push(nodeIndex);

	// ��������
	int idx = 0;
	int value = 0;
	//while (!m_pBfsQueue->empty()) {
	while(!q.empty()) {
		// ����
		//idx = m_pBfsQueue->front();
		//m_pBfsQueue->pop();
		idx = q.front();
		q.pop();

		// �ڽӵ㣨���ڽӾ���
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(idx, i, value);
			if (value != 0 && !m_pNodeArray[i].m_bIsVisited) {
				// ����
				cout << m_pNodeArray[i].m_cData << " ";
				m_pNodeArray[i].m_bIsVisited = true;
				// ���
				//m_pBfsQueue->push(i);
				q.push(i);
			}
		}
	}
}

bool CMap::getValueFromMatrix(int row, int col, int& val)
{
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	// @deprecated
	// û�а���imooc��Ƶ��Ľ��ܱ�д�����Բ���Ҫʹ�����������
}
