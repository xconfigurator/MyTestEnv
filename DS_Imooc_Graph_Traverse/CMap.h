#pragma once
#include <vector>
#include "Node.h"
using namespace std;

class CMap
{
public:
	CMap(int capacity);
	virtual ~CMap();
	bool addNode(Node* pNode);												// 设置顶点：：向图中加入顶点
	void resetNode();														// 设置顶点：：重置顶点（图中所有节点都重置为没有访问过）
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);	// 设置边：：为有向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);	// 设置边：：为无向图设置邻接矩阵
	
	void printMatrix();	// 打印邻接矩阵

	void depthFirstTraverse(int nodeIndex);		// 深度优先遍历
	void breadthFirstTraverse(int nodeIndex);	// 广度优先遍历
	
private:
	bool getValueFromMatrix(int row, int col, int &val);	// 从矩阵中获取权值(val为0说明顶点不相连， val如果不为0说明顶点相连)// TODO 12:45
	void breadthFirstTraverseImpl(vector<int> preVec);		// 广度优先遍历实现函数
	// TODO

private:
	int m_iCapacity;			// 图中最多可以容纳的顶点数
	int m_iNodeCount;			// 已添加的顶点个数
	Node* m_pNodeArray;			// 用来存放顶点数组
	int* m_pMatrix;				// 用来存放邻接矩阵
};