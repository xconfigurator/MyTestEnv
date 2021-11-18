/****************************************************/
/*
����C++ʵ��
ʹ����ģ��
Visual Studio 2015�������ģ�廹��ֻ��д��.h�ļ��С�
@since 2016/12/28 update 2016/12/22
@author liuyang
*/
/****************************************************/
#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
using namespace std;

template<class T>
class Node {
	friend ostream& operator<<(ostream& os, const Node<T>& n) {
		os << n.data << endl;
		return os;
	}
public:
	/*
	Node(const Node &n) {
		this->data = n.data;
		this->next = n.next;
	}
	*/
	Node() {}
	Node(T _data) {
		data = _data;
	}
	bool operator==(const Node& n) {// .equals()
		return (*this.data == n.data);
	}
public:
	T data;
	Node* next;
};


template<class T>
class LinkedList {
public:
	LinkedList();			// BOOL InitList(List **list)�������Ա�
	virtual ~LinkedList();  // void DestroyList(List *list)�������Ա�
	void ClearList();       // void ClearList(List *list)������Ա�
	bool ListEmpty();       // BOOL ListEmpty(List *list) �ж����Ա��Ƿ�Ϊ��
	int ListLength();       // int ListLength(List *list) ��ȡ���Ա��Ƿ�Ϊ��
	bool GetElem(int i, Node<T>* e);                   // BOOL GetElem(List *list, int i, Elem *e); ��ȡָ��Ԫ��
	int LocateElem(Node<T>* e);                        // int LocateElem(List *list, Elem *e) Ѱ�ҵ�һ������e������Ԫ�ص�λ��
	bool PriorElem(Node<T>* currentElem, Node<T>* preElem);    // BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem); ��ȡָ��Ԫ�ص�ǰ��
	bool NextElem(Node<T>* currentElem, Node<T>* nextElem);    // BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem); ��ȡָ��Ԫ�صĺ��
	bool ListInsert(int i, Node<T>* e);                // BOOL ListInsert(List *list, int i, Elem *e); �ڵ�i��λ�ò���Ԫ��
	bool ListDelete(int i, Node<T>* e);                // BOOL ListDelete(List *list, int i, Elem *e); ɾ����i��λ�õ�Ԫ��
	bool ListInsertHead(Node<T>* e);
	bool ListInsertTail(Node<T>* e);
	void ListTraverse();    // void ListTraverse(List *list); �������Ա�
private:
	Node<T>* m_pList;
	// int m_iSize;//������Ҫ�̶�size��
	int m_iLength;
};

template<class T>
LinkedList<T>::LinkedList() {
	m_pList = new Node<T>();// ͷ���
	m_pList->data = T();
	m_pList->next = NULL;
	m_iLength = 0;// ͷ��㲻����
}

// ��ע��
template<class T>
LinkedList<T>::~LinkedList() {
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

// ��ע��
template<class T>
void LinkedList<T>::ClearList() {
	Node<T>* currentNode = m_pList->next;
	Node<T>* nextNode = NULL;
	while (currentNode != NULL) {
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	m_pList->next = NULL;
	m_iLength = 0;
}

template<class T>
bool LinkedList<T>::ListEmpty() {
	return m_iLength == 0 ? true : false;
}

template<class T>
int LinkedList<T>::ListLength() {
	return m_iLength;
}

template<class T>
bool LinkedList<T>::ListInsertHead(Node<T>* e) {
	Node<T>* temp = m_pList->next;
	Node<T>* newNode = new Node<T>();// һ���Ӷ��������ڴ棡
	if (NULL == newNode) {
		return false;
	}
	newNode->data = e->data;
	newNode->next = temp;
	m_pList->next = newNode;
	m_iLength++;
	return true;
}

template<class T>
bool LinkedList<T>::ListInsertTail(Node<T>* e) {
	Node<T>* currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	Node<T>* newNode = new Node<T>();
	if (NULL == newNode) {
		return false;
	}
	newNode->data = e->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

// ��ע��
template <class T>
bool LinkedList<T>::ListInsert(int i, Node<T>* e) {
	// if i = 0 then ListInsertHead
	// if i = m_iLength then ListInsertTail
	if (i < 0 || i > m_iLength) {
		return false;
	}
	Node<T>* currentNode = m_pList;
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}
	Node<T>* newNode = new Node<T>();
	if (NULL == newNode) {
		return false;
	}
	newNode->data = e->data;
	newNode->next = currentNode->next;// ע��������˳�� 
	currentNode->next = newNode;// ע��������˳��
	m_iLength++;
	return true;
}

// ��ע��
template<class T>
bool LinkedList<T>::ListDelete(int i, Node<T>* e) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node<T>* currentNode = m_pList;
	Node<T>* currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) {// !!!!!!!!!!!!!!!!!!!! ����k<i ����k<=i?
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	e->data = currentNode->data;
	e->next = currentNode->next;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

template<class T>
bool LinkedList<T>::GetElem(int i, Node<T>* e) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node<T>* currentNode = m_pList;
	Node<T>* currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) {// !!!!!!!!!!!!!!!!!!!! ����k<i ����k<=i?
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	e->data = currentNode->data;
	e->next = currentNode->next;
	return true;
}

/*
����0Ϊû�ҵ���
*/
template<class T>
int LinkedList<T>::LocateElem(Node<T>* e) {
	Node<T>* currentNode = m_pList;
	int idx = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		//idx++;// !!!!!!!!!!!��Ҫ�ŵ����
		if (currentNode->data == e->data) {
			break;
		}
		idx++;// !!!!!!!!!!!!�ŵ����
	}
	return idx;
}

template<class T>
bool LinkedList<T>::PriorElem(Node<T>* currentElem, Node<T>* preElem) {
	Node<T>* currentNode = m_pList;
	Node<T>* preNode = NULL;
	while (currentNode->next != NULL) {
		preNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == currentElem->data) {
			if (preNode == m_pList) {// ���ǵ�һ���ڵ�
				return false;
			}
			preElem->data = preNode->data;
			return true;
		}
	}
	return false;
}

template<class T>
bool LinkedList<T>::NextElem(Node<T>* currentElem, Node<T>* nextElem) {
	Node<T>* currentNode = m_pList;
	//Node<T> *preNode = NULL;
	while (currentNode->next != NULL) {
		//preNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == currentElem->data) {
			//if (preNode = m_pList) {
			//	return false;
			//}
			if (currentNode->next == NULL) {// �������һ���ڵ�
				return false;
			}
			nextElem->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

template<class T>
void LinkedList<T>::ListTraverse() {
	Node<T>* currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		cout << currentNode->data << endl;
	}
}


#endif
