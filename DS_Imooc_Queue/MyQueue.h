#ifndef _HEADER_MY_QUEUE_
#define _HEADER_MY_QUEUE_
/****************************************************/
/*
���ζ���C++ʵ��
@since 2016/12/15
@author liuyang
*/
/****************************************************/
class MyQueue
{
public:
	MyQueue(int queueCapacity);    //InitQueue(&Q) ��������
	virtual ~MyQueue();            //DestroyQueue(&Q) ���ٶ���
	void ClearQueue();            //ClearQueue(&Q) ��ն���
	bool QueueEmpty() const;    //QueueEmpty(Q) �пն���
	bool QueueFull() const;        //�ж����Ƿ�����
	int QueueLength() const;    //QueueLength(Q) ���г���
	bool EnQueue(int element);    //EnQueue(&Q element) ��Ԫ�����
	bool DeQueue(int& element);    //DeQueue(&Q &element) ��Ԫ�س���
	void QueueTraverse();        //QueueTraverse(Q, visit()) ��������
private:
	int* m_pQueue;                //��������ָ��
	int m_iQueueLen;            //����Ԫ�ظ���
	int m_iQueueCapacity;        //������������
	int m_iHead;                //��ͷ
	int m_iTail;                //��β
};
#endif// !_HEADER_MY_QUEUE_