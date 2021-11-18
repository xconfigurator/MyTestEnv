#ifndef _HEADER_MY_STACK_
#define _HEADER_MY_STACK_
/****************************************************/
/*
栈C++实现
使用类模板
Visual Studio 2015，这个类模板还是只能写在.h文件中。
@since 2016/12/16
@author liuyang
*/
/****************************************************/
#include<iostream>
using namespace std;

template <typename T>
class MyStack
{
public:
	MyStack(int size);			// InitStack(&S) 构造一个空栈
	virtual ~MyStack();			// DestroyStack(&S) 回收栈空间内存
	bool stackEmpty();			// StackEmpty(S)判断栈是否唯恐，为空返回true，非空返回false
	bool stackFull();			// 判断栈是否已满，为满返回true，不满返回false
	void clearStack();			// ClearStack(&S)清空栈
	int stackLength();			// StackLength(S) 已有元素的个数
	bool push(T element);	// Push(&S, e)元素入栈，栈顶上升
	bool pop(T& element);	// Pop(&S, &e)元素出栈，栈顶下降
	void stackTraverse(bool isFromBottom);		// StackTraverse(S, visit())遍历栈中所有元素
private:
	T* m_pBuffer;			// 栈空间指针
	int m_iSize;				// 栈容量
	int m_iTop;					// 栈顶，栈中元素个数
};

// 看来到了Visual Studio 2015，这个类模板还是只能写在.h文件中。

template <typename T>
MyStack<T>::MyStack(int size) {//InitStack(&S) 构造一个空栈
	m_iSize = size;
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack() {// DestroyStack(&S) 回收栈空间内存
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty() {// StackEmpty(S)判断栈是否唯恐，为空返回true，非空返回false
	return m_iTop == 0 ? true : false;
}

template <typename T>
bool MyStack<T>::stackFull() {// 判断栈是否已满，为满返回true，不满返回false
	return m_iTop == m_iSize ? true : false;
}

template <typename T>
void MyStack<T>::clearStack() {// ClearStack(&S)清空栈
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {// StackLength(S) 已有元素的个数
	return m_iTop;
}

// Stack关注点
template <typename T>
bool MyStack<T>::push(T element) {// Push(&S, e)元素入栈，栈顶上升
	if (stackFull()) {
		return false;
	}

	m_pBuffer[m_iTop++] = element;
	return true;
}

// Stack关注点
template <typename T>
bool MyStack<T>::pop(T& element) {// Pop(&S, &e)元素出栈，栈顶下降
	if (stackEmpty()) {
		return false;
	}

	element = m_pBuffer[--m_iTop];
	return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom) {// StackTraverse(S, visit())遍历栈中所有元素
	if (isFromBottom) {
		// from bottom
		for (int i = 0; i < stackLength(); i++) {
			cout << m_pBuffer[i] << endl;
		}
	}
	else {
		// from top to bottom
		for (int i = stackLength() - 1; i >= 0; i--) {
			cout << m_pBuffer[i] << endl;
		}
	}
}

#endif // !_HEADER_MY_STACK_

