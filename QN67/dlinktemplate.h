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
// ��ӵ������β�� ��pLast֮��
template<class T>
void DLink<T>::Add(T& t) {
	Node<T>* temp = new Node<T>(t);
	temp->pPrev = pLast;
	// �ǿ�����
	if (pLast) {
		pLast->pNext = temp;
	}

	// Because temp is last, its nextis always NULL
	temp->pNext = NULL;
	
	// The last member
	pLast = temp;

	// ����������Ϊ��
	if (NULL == pFirst) {
		pFirst = temp;
	}
}

// Remove
template<class T>
void DLink<T>::Remove(T& t) {
	// ������ڵ�
	Node<T>* n = NULL;
	for (Node<T>* pF = pFirst; pF != NULL; pF = pF->pNext) {
		if (pF->data == t) {
			n = pF;
			break;
		}
	}
	
	// û�ҵ���ʲôҲ����
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