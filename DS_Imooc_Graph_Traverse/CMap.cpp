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
	//m_pBfsQueue = new queue<int>();						// BFS需要用到的队列
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
// DFS伪码
/*
伪码描述（浙大）
void DFS () {
	// TODO

}
*/

// BFS（BFS实现遵从浙大数据结构视频介绍方法）
void CMap::breadthFirstTraverse(int nodeIndex)
{
	// 准备
	queue<int> q;// 不是递归函数，可以使用局部队列。

	// 访问
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// 入队
	// 注：这里为了跟浙大视频靠拢，采用定义成员变量Queue的方式, 视频中采用了另外一种介绍方式。个人以为比较凌乱，就不要再看了。
	//m_pBfsQueue->push(nodeIndex);
	q.push(nodeIndex);

	// 遍历队列
	int idx = 0;
	int value = 0;
	//while (!m_pBfsQueue->empty()) {
	while(!q.empty()) {
		// 出队
		//idx = m_pBfsQueue->front();
		//m_pBfsQueue->pop();
		idx = q.front();
		q.pop();

		// 邻接点（查邻接矩阵）
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(idx, i, value);
			if (value != 0 && !m_pNodeArray[i].m_bIsVisited) {
				// 访问
				cout << m_pNodeArray[i].m_cData << " ";
				m_pNodeArray[i].m_bIsVisited = true;
				// 入队
				//m_pBfsQueue->push(i);
				q.push(i);
			}
		}
	}
}
// BFS伪码
/*
伪码描述（浙大）
void BFS (Vertex S) {
	visited[S] = true;
	Enqueue(S, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (V 的每个临接点 W) {
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(W, Q);
			}
		}
	}
}
*/
// 无权图的单源最短路算法伪码(与BFS类似)。题目例子：007
/*
伪码描述（浙大）
T = O(|V| + |E|) 说明： T = O(|V|（每个顶点入队、出队一次就是2|V|） + |E|（每个邻接点）)
void Unweighted( Vertex S) {
	Enqueue(S, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for ( V 的每个邻接点 W) {
			if (dist[W] == -1) {// 条件与BFS不同 但语义也是“如果没有访问过”
				dist[W] = dist[V] + 1;// 与BFS不同 但语义也是“访问”
				path[W] = V;
				Enqueue(W, Q);
			}
		}
	}
}
// dist[S] = 0 
// dist[W] = S到W的最短距离
// path[W] = S到W的路上经过的某顶点 
*/

// 有权图的单源最短路算法:Dijkstra (03:12左右开始)
/*
伪码描述（浙大)10:06开始
T = O(?) 
很大程度取决于如何实现“V = 未被收录顶点中dist最小者；”
void Dijkstra( Vertex s) {
	while (1) {
		// 策略1. 直接扫描所有未收录顶点 - O(|V|) => T = O(|V||V| + |E|) 对稠密图效果好
		// 策略2. 将dist存在最小堆中 - O(log|V|) => T = O(|V|log|V| + |E|log|V|) = O(|E|log|V|) 对稀疏图效果好 (通常认为边的个数要比点的个数多一点，至少是同一个数量级的，否则整个图都不连通了。)
		V = 未被收录顶点中dist最小者；
		if ( 这样的V不存在 ) {
			break;
		}
		collected[V] = true;
		for ( V 的每个邻接点 W) {
			if ( collected[W] == false ) {
				if (dist[V] + E<v, w> < dist[W]) {
					dist[W] = dist[V] + E<v, w>;// 策略：跟随前面的策略变化。若策略1则就是一个简单赋值语句 O(1)。若策略2，则需要O(log|V|)(因为不仅要更新，还需要把值插回最小堆)
					path[W] = V;
				}
			}
		}
	}
}
*/

// 多源最短路算法:Floyd
/*
伪码描述（浙大)
T = O(|V||V||V|)
适用于稠密图（相较于多次使用单源最短路算法，在针对稀疏图、稠密图采用不同的优化策略后能达到的最好时间复杂度来说）
既然是针对稠密图，则选用邻接矩阵来表达稠密图。
void Floyd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[i][j] = G[i][j];
			path[i][j] = -1;
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][k] + D[k][i] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
// D直接初始化为邻接矩阵，对角元是0。
*/


bool CMap::getValueFromMatrix(int row, int col, int& val)
{
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	// @deprecated
	// 没有按照imooc视频里的介绍编写，所以不需要使用这个函数。
}
