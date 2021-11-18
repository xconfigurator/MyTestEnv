/*
@since 2016/12/15
@Author liuyang
队列
编译环境：Visual Studio 2015 Community
*/
#include <iostream>
#include "MyQueue.h"
using namespace std;
int main() {

	MyQueue* myQueue = new MyQueue(4);
	myQueue->EnQueue(1);
	myQueue->EnQueue(2);
	myQueue->EnQueue(3);
	myQueue->EnQueue(4);
	myQueue->EnQueue(5);
	myQueue->QueueTraverse();
	cout << "===================" << endl;
	int temp = 0;
	myQueue->DeQueue(temp);
	cout << "DeQueue = " << temp << endl;
	myQueue->DeQueue(temp);
	cout << "DeQueue = " << temp << endl;
	cout << "===================" << endl;
	myQueue->EnQueue(6);
	myQueue->EnQueue(7);
	myQueue->EnQueue(8);
	myQueue->QueueTraverse();

	delete myQueue;
	myQueue = NULL;
	return 0;
}