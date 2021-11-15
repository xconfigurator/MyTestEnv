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
}

CMap::~CMap()
{
	if (NULL != m_pNodeArray) delete[] m_pNodeArray;
	if (NULL != m_pMatrix) delete[] m_pMatrix;
}

bool CMap::addNode(Node* pNode)
{
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
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

void CMap::printMatrix()
{
	for (int i = 0; i < m_iCapacity; i++) {
		for (int j = 0; j < m_iCapacity; j++) {
			cout << m_pMatrix[i * m_iCapacity + j] << "\t";
		}
		cout << endl;
	}
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
