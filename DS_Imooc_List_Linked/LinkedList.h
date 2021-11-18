/****************************************************/
/*
链表C++实现
使用类模板
Visual Studio 2015，这个类模板还是只能写在.h文件中。
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
	LinkedList();			// BOOL InitList(List **list)创建线性表
	virtual ~LinkedList();  // void DestroyList(List *list)销毁线性表
	void ClearList();       // void ClearList(List *list)清空线性表
	bool ListEmpty();       // BOOL ListEmpty(List *list) 判断线性表是否为空
	int ListLength();       // int ListLength(List *list) 获取线性表是否为空
	bool GetElem(int i, Node<T>* e);                   // BOOL GetElem(List *list, int i, Elem *e); 获取指定元素
	int LocateElem(Node<T>* e);                        // int LocateElem(List *list, Elem *e) 寻找第一个满足e的数据元素的位序
	bool PriorElem(Node<T>* currentElem, Node<T>* preElem);    // BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem); 获取指定元素的前驱
	bool NextElem(Node<T>* currentElem, Node<T>* nextElem);    // BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem); 获取指定元素的后继
	bool ListInsert(int i, Node<T>* e);                // BOOL ListInsert(List *list, int i, Elem *e); 在第i个位置插入元素
	bool ListDelete(int i, Node<T>* e);                // BOOL ListDelete(List *list, int i, Elem *e); 删除第i个位置的元素
	bool ListInsertHead(Node<T>* e);
	bool ListInsertTail(Node<T>* e);
	void ListTraverse();    // void ListTraverse(List *list); 遍历线性表
private:
	Node<T>* m_pList;
	// int m_iSize;//链表不需要固定size。
	int m_iLength;
};

template<class T>
LinkedList<T>::LinkedList() {
	m_pList = new Node<T>();// 头结点
	m_pList->data = T();
	m_pList->next = NULL;
	m_iLength = 0;// 头结点不计数
}

// 关注点
template<class T>
LinkedList<T>::~LinkedList() {
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

// 关注点
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
	Node<T>* newNode = new Node<T>();// 一定从堆中申请内存！
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

// 关注点
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
	newNode->next = currentNode->next;// 注意这两句顺序 
	currentNode->next = newNode;// 注意这两句顺序
	m_iLength++;
	return true;
}

// 关注点
template<class T>
bool LinkedList<T>::ListDelete(int i, Node<T>* e) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node<T>* currentNode = m_pList;
	Node<T>* currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) {// !!!!!!!!!!!!!!!!!!!! 不是k<i 而是k<=i?
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
	for (int k = 0; k <= i; k++) {// !!!!!!!!!!!!!!!!!!!! 不是k<i 而是k<=i?
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	e->data = currentNode->data;
	e->next = currentNode->next;
	return true;
}

/*
返回0为没找到。
*/
template<class T>
int LinkedList<T>::LocateElem(Node<T>* e) {
	Node<T>* currentNode = m_pList;
	int idx = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		//idx++;// !!!!!!!!!!!不要放到这里？
		if (currentNode->data == e->data) {
			break;
		}
		idx++;// !!!!!!!!!!!!放到这里？
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
			if (preNode == m_pList) {// 不是第一个节点
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
			if (currentNode->next == NULL) {// 不是最后一个节点
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
