/*
������Stack��
Larry Nyhoff �����ݽṹ���㷨���� C++������������2�棩�� p290

˵������̬����汾

@author liuyang copy from Larry Nyhoff
@since 2020/12/15
*/
#include <iostream>

#ifndef STACK
#define STACK

const int STACK_CAPACITY = 128;
typedef int StackElement;

class Stack {
public:
	Stack();
	bool empty() const;
	void push(const StackElement& value);
	void display(ostream& out) const;
	StackElement top() const;
	void pop();

private:
	StackElement myArray[STACK_CAPACITY];
	int myTop;
};

#endif