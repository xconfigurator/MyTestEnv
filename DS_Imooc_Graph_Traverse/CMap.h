#pragma once
#include <vector>
#include "Node.h"
using namespace std;

class CMap
{
public:
	CMap(int capacity);
	virtual ~CMap();
	bool addNode(Node* pNode);												// ���ö��㣺����ͼ�м��붥��
	void resetNode();														// ���ö��㣺�����ö��㣨ͼ�����нڵ㶼����Ϊû�з��ʹ���
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);	// ���ñߣ���Ϊ����ͼ�����ڽӾ���
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);	// ���ñߣ���Ϊ����ͼ�����ڽӾ���
	
	void printMatrix();	// ��ӡ�ڽӾ���

	void depthFirstTraverse(int nodeIndex);		// ������ȱ���
	void breadthFirstTraverse(int nodeIndex);	// ������ȱ���
	
private:
	bool getValueFromMatrix(int row, int col, int &val);	// �Ӿ����л�ȡȨֵ(valΪ0˵�����㲻������ val�����Ϊ0˵����������)// TODO 12:45
	void breadthFirstTraverseImpl(vector<int> preVec);		// ������ȱ���ʵ�ֺ���
	// TODO

private:
	int m_iCapacity;			// ͼ�����������ɵĶ�����
	int m_iNodeCount;			// ����ӵĶ������
	Node* m_pNodeArray;			// ������Ŷ�������
	int* m_pMatrix;				// ��������ڽӾ���
};