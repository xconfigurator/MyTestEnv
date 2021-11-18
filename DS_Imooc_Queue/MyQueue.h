#ifndef _HEADER_MY_QUEUE_
#define _HEADER_MY_QUEUE_
/****************************************************/
/*
环形队列C++实现
@since 2016/12/15
@author liuyang
*/
/****************************************************/
class MyQueue
{
public:
	MyQueue(int queueCapacity);    //InitQueue(&Q) 创建队列
	virtual ~MyQueue();            //DestroyQueue(&Q) 销毁队列
	void ClearQueue();            //ClearQueue(&Q) 清空队列
	bool QueueEmpty() const;    //QueueEmpty(Q) 判空队列
	bool QueueFull() const;        //判队列是否已满
	int QueueLength() const;    //QueueLength(Q) 队列长度
	bool EnQueue(int element);    //EnQueue(&Q element) 新元素入队
	bool DeQueue(int& element);    //DeQueue(&Q &element) 首元素出队
	void QueueTraverse();        //QueueTraverse(Q, visit()) 遍历队列
private:
	int* m_pQueue;                //队列数组指针
	int m_iQueueLen;            //队列元素个数
	int m_iQueueCapacity;        //队列数组容量
	int m_iHead;                //队头
	int m_iTail;                //队尾
};
#endif// !_HEADER_MY_QUEUE_