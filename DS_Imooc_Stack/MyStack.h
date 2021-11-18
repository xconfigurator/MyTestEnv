#ifndef _HEADER_MY_STACK_
#define _HEADER_MY_STACK_
/****************************************************/
/*
ջC++ʵ��
ʹ����ģ��
Visual Studio 2015�������ģ�廹��ֻ��д��.h�ļ��С�
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
	MyStack(int size);			// InitStack(&S) ����һ����ջ
	virtual ~MyStack();			// DestroyStack(&S) ����ջ�ռ��ڴ�
	bool stackEmpty();			// StackEmpty(S)�ж�ջ�Ƿ�Ψ�֣�Ϊ�շ���true���ǿշ���false
	bool stackFull();			// �ж�ջ�Ƿ�������Ϊ������true����������false
	void clearStack();			// ClearStack(&S)���ջ
	int stackLength();			// StackLength(S) ����Ԫ�صĸ���
	bool push(T element);	// Push(&S, e)Ԫ����ջ��ջ������
	bool pop(T& element);	// Pop(&S, &e)Ԫ�س�ջ��ջ���½�
	void stackTraverse(bool isFromBottom);		// StackTraverse(S, visit())����ջ������Ԫ��
private:
	T* m_pBuffer;			// ջ�ռ�ָ��
	int m_iSize;				// ջ����
	int m_iTop;					// ջ����ջ��Ԫ�ظ���
};

// ��������Visual Studio 2015�������ģ�廹��ֻ��д��.h�ļ��С�

template <typename T>
MyStack<T>::MyStack(int size) {//InitStack(&S) ����һ����ջ
	m_iSize = size;
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack() {// DestroyStack(&S) ����ջ�ռ��ڴ�
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty() {// StackEmpty(S)�ж�ջ�Ƿ�Ψ�֣�Ϊ�շ���true���ǿշ���false
	return m_iTop == 0 ? true : false;
}

template <typename T>
bool MyStack<T>::stackFull() {// �ж�ջ�Ƿ�������Ϊ������true����������false
	return m_iTop == m_iSize ? true : false;
}

template <typename T>
void MyStack<T>::clearStack() {// ClearStack(&S)���ջ
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {// StackLength(S) ����Ԫ�صĸ���
	return m_iTop;
}

// Stack��ע��
template <typename T>
bool MyStack<T>::push(T element) {// Push(&S, e)Ԫ����ջ��ջ������
	if (stackFull()) {
		return false;
	}

	m_pBuffer[m_iTop++] = element;
	return true;
}

// Stack��ע��
template <typename T>
bool MyStack<T>::pop(T& element) {// Pop(&S, &e)Ԫ�س�ջ��ջ���½�
	if (stackEmpty()) {
		return false;
	}

	element = m_pBuffer[--m_iTop];
	return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom) {// StackTraverse(S, visit())����ջ������Ԫ��
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

