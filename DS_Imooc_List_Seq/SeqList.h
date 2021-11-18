/****************************************************/
/*
顺序表C++实现
使用类模板
Visual Studio 2015，这个类模板还是只能写在.h文件中。
@since 2016/12/18
@author liuyang
*/
/****************************************************/
#ifndef _SEQ_LIST_
#define _SEQ_LIST_
#include <iostream>
using namespace std;

template <class T>
class SeqList {
public:
	SeqList(int size);		// BOOL InitList(List **list)创建线性表
	virtual ~SeqList();		// void DestroyList(List *list)销毁线性表
	void ClearList();		// void ClearList(List *list)清空线性表
	bool ListEmpty();		// BOOL ListEmpty(List *list) 判断线性表是否为空
	int ListLength();		// int ListLength(List *list) 获取线性表是否为空
	bool GetElem(int i, T* e);					// BOOL GetElem(List *list, int i, Elem *e); 获取指定元素
	int LocateElem(T* e);						// int LocateElem(List *list, Elem *e) 寻找第一个满足e的数据元素的位序
	bool PriorElem(T* currentElem, T* preElem);	// BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem); 获取指定元素的前驱
	bool NextElem(T* currentElem, T* nextElem);	// BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem); 获取指定元素的后继
	bool ListInsert(int i, T* e);				// BOOL ListInsert(List *list, int i, Elem *e); 在第i个位置插入元素
	bool ListDelete(int i, T* e);				// BOOL ListDelete(List *list, int i, Elem *e); 删除第i个位置的元素
	void ListTraverse();	// void ListTraverse(List *list); 遍历线性表
private:
	T* m_pList;
	int m_iSize;	// 容量
	int m_iLength;	// 当前大小
};

template <class T>
SeqList<T>::SeqList(int size) {
	m_iSize = size;
	m_pList = new T[m_iSize];
	m_iLength = 0;
}

template <class T>
SeqList<T>::~SeqList() {
	delete[] m_pList;
	m_pList = NULL;
}

template <class T>
void SeqList<T>::ClearList() {
	m_iLength = 0;
}

template <class T>
bool SeqList<T>::ListEmpty() {
	return m_iLength == 0 ? true : false;
}

template <class T>
int SeqList<T>::ListLength() {
	return m_iLength;
}


template <class T>
bool SeqList<T>::GetElem(int i, T* e) {
	if (m_iLength == 0) {
		return false;
	}

	if (i < 0 || i >= m_iLength) {
		return false;
	}

	*e = m_pList[i];
	return true;
}

// 关注点
template <class T>
int SeqList<T>::LocateElem(T* e) {
	for (int i = 0; i < m_iLength; i++) {
		if (m_pList[i] == *e) {
			return i;
		}
	}
	return -1;
}

// 关注点
template <class T>
bool SeqList<T>::PriorElem(T* currentElem, T* preElem) {
	int idx = LocateElem(currentElem);
	if (-1 == idx) {// 没找到
		return false;
	}
	if (0 == idx) {// 没有前驱
		return false;
	}

	*preElem = m_pList[--idx];
	return true;
}

// 关注点
template <class T>
bool SeqList<T>::NextElem(T* currentElem, T* nextElem) {
	int idx = LocateElem(currentElem);
	if (-1 == idx) {// 没找到
		return false;
	}
	if ((m_iLength - 1) == idx) {// 没有后继
		return false;
	}

	*nextElem = m_pList[++idx];
	return true;
}

// 关注点
template <class T>
bool SeqList<T>::ListInsert(int i, T* e) {

	if (m_iLength == m_iSize) {// 判断容器容量
		return false;
	}

	if (i < 0 || i > m_iLength) {//  判断逻辑容量
		return false;
	}
	for (int k = m_iLength - 1; k >= i; k--) {//移动
		m_pList[k + 1] = m_pList[k];
	}

	m_pList[i] = *e;// 插入
	m_iLength++;

	return true;
}

// 关注点
template <class T>
bool SeqList<T>::ListDelete(int i, T* e) {

	if (m_iLength == 0) {// 已经为空则直接返回
		return false;
	}

	if (i < 0 || i > m_iLength) {//  判断逻辑容量
		return false;
	}

	*e = m_pList[i];
	for (int k = i + 1; k <= m_iLength - 1; k++) {
		m_pList[k - 1] = m_pList[k];
	}
	m_iLength--;
	return true;
}

template <class T>
void SeqList<T>::ListTraverse() {
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pList[i] << endl;
	}
}

#endif
