#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	Node(T& rt) :data(rt), pNext(NULL), pPrev(NULL) {};
	Node* pNext;
	Node* pPrev;
	T& data;
};

template<class T>
class DLink {
public:
	DLink();
	void Add(T&);
	void Remove(T&);
	void PrintFList();
	void PrintLList();
	~DLink();
protected:
	Node<T>* pFirst;	//first Node in list
	Node<T>* pLast;		//last Node in list
};

template<class T>
DLink<T>::DLink() {
	pFirst = pLast = NULL;
}

// Add
// 添加到链表的尾部 即pLast之后
template<class T>
void DLink<T>::Add(T& t) {
	Node<T>* temp = new Node<T>(t);
	temp->pPrev = pLast;
	// 非空链表
	if (pLast) {
		pLast->pNext = temp;
	}

	// Because temp is last, its nextis always NULL
	temp->pNext = NULL;
	
	// The last member
	pLast = temp;

	// 如果这个链表为空
	if (NULL == pFirst) {
		pFirst = temp;
	}
}

// Remove
template<class T>
void DLink<T>::Remove(T& t) {
	// 找这个节点
	Node<T>* n = NULL;
	for (Node<T>* pF = pFirst; pF != NULL; pF = pF->pNext) {
		if (pF->data == t) {
			n = pF;
			break;
		}
	}
	
	// 没找到就什么也不做
	if (NULL == n) {
		return;
	}

	// Get the address of Node of it's neighbors
	Node<T>* pPrevS = n->pPrev;
	Node<T>* pNextS = n->pNext;

	// If n have a predecessor 
	if (pPrevS) {
		pPrevS->pNext = pNextS;
	} else {
		pFirst = pNextS;
	}

	// if n have a successor 
	if (pNextS) {
		pNextS->pPrev = pPrevS;
	} else {
		pLast = pPrevS;
	}

	delete n;
}

template<class T>
DLink<T>::~DLink() {
	if (NULL == pFirst) {
		return;
	}
	Node<T>* pN = pFirst;
	Node<T>* pF;
	do {
		pF = pN;
		pN = pN->pNext;
		delete pF;
	} while (pN);
}

template<class T>
void DLink<T>::PrintFList() {
	for (Node<T>* pF = pFirst; pF != NULL; pF = pF->pNext) {
		cout << pF->data << " ";
	}
	cout << endl;
}

template<class T>
void DLink<T>::PrintLList() {
	for (Node<T>* pF = pLast; pF != NULL; pF = pF->pPrev) {
		cout << pF->data << " ";
	}
	cout << endl;
}