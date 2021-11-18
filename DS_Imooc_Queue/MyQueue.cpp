#include <iostream>
#include "MyQueue.h"
using namespace std;
MyQueue::MyQueue(int queueCapacity) {//InitQueue(&Q) 创建队列
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[m_iQueueCapacity];
	ClearQueue();
}
// 虚函数声明的地方写virtual，实现的地方不写virtual
MyQueue::~MyQueue() {//DestroyQueue(&Q) 销毁队列
	delete[] m_pQueue;// 注意！加[]
	m_pQueue = NULL;
}
void MyQueue::ClearQueue() {//ClearQueue(&Q) 清空队列
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}
bool MyQueue::QueueEmpty() const {//QueueEmpty(Q) 判空队列
	return m_iQueueLen == 0 ? true : false;
}
bool MyQueue::QueueFull() const {
	return m_iQueueLen == m_iQueueCapacity ? true : false;
}
int MyQueue::QueueLength() const {//QueueLength(Q) 队列长度
	return m_iQueueLen;
}
// Queue关注点
bool MyQueue::EnQueue(int element) {//EnQueue(&Q element) 新元素入队
	if (QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = ++m_iTail % m_iQueueCapacity;
	m_iQueueLen++;
	return true;
}
// Queue关注点
bool MyQueue::DeQueue(int& element) {//DeQueue(&Q &element) 首元素出队
	if (QueueEmpty()) {
		return false;
	}

	element = m_pQueue[m_iHead];
	m_iHead = ++m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}
// Queue关注点
void MyQueue::QueueTraverse() {//QueueTraverse(Q, visit()) 遍历队列
	for (int i = m_iHead; i < m_iHead + m_iQueueLen; i++) {
		cout << m_pQueue[i % m_iQueueCapacity] << endl;
	}
}