#include <iostream>
#include "MyQueue.h"
using namespace std;
MyQueue::MyQueue(int queueCapacity) {//InitQueue(&Q) ��������
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[m_iQueueCapacity];
	ClearQueue();
}
// �麯�������ĵط�дvirtual��ʵ�ֵĵط���дvirtual
MyQueue::~MyQueue() {//DestroyQueue(&Q) ���ٶ���
	delete[] m_pQueue;// ע�⣡��[]
	m_pQueue = NULL;
}
void MyQueue::ClearQueue() {//ClearQueue(&Q) ��ն���
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}
bool MyQueue::QueueEmpty() const {//QueueEmpty(Q) �пն���
	return m_iQueueLen == 0 ? true : false;
}
bool MyQueue::QueueFull() const {
	return m_iQueueLen == m_iQueueCapacity ? true : false;
}
int MyQueue::QueueLength() const {//QueueLength(Q) ���г���
	return m_iQueueLen;
}
// Queue��ע��
bool MyQueue::EnQueue(int element) {//EnQueue(&Q element) ��Ԫ�����
	if (QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = ++m_iTail % m_iQueueCapacity;
	m_iQueueLen++;
	return true;
}
// Queue��ע��
bool MyQueue::DeQueue(int& element) {//DeQueue(&Q &element) ��Ԫ�س���
	if (QueueEmpty()) {
		return false;
	}

	element = m_pQueue[m_iHead];
	m_iHead = ++m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}
// Queue��ע��
void MyQueue::QueueTraverse() {//QueueTraverse(Q, visit()) ��������
	for (int i = m_iHead; i < m_iHead + m_iQueueLen; i++) {
		cout << m_pQueue[i % m_iQueueCapacity] << endl;
	}
}