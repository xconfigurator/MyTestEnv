/****************************************************/
/*
˳���C++ʵ��
ʹ����ģ��
Visual Studio 2015�������ģ�廹��ֻ��д��.h�ļ��С�
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
	SeqList(int size);		// BOOL InitList(List **list)�������Ա�
	virtual ~SeqList();		// void DestroyList(List *list)�������Ա�
	void ClearList();		// void ClearList(List *list)������Ա�
	bool ListEmpty();		// BOOL ListEmpty(List *list) �ж����Ա��Ƿ�Ϊ��
	int ListLength();		// int ListLength(List *list) ��ȡ���Ա��Ƿ�Ϊ��
	bool GetElem(int i, T* e);					// BOOL GetElem(List *list, int i, Elem *e); ��ȡָ��Ԫ��
	int LocateElem(T* e);						// int LocateElem(List *list, Elem *e) Ѱ�ҵ�һ������e������Ԫ�ص�λ��
	bool PriorElem(T* currentElem, T* preElem);	// BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem); ��ȡָ��Ԫ�ص�ǰ��
	bool NextElem(T* currentElem, T* nextElem);	// BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem); ��ȡָ��Ԫ�صĺ��
	bool ListInsert(int i, T* e);				// BOOL ListInsert(List *list, int i, Elem *e); �ڵ�i��λ�ò���Ԫ��
	bool ListDelete(int i, T* e);				// BOOL ListDelete(List *list, int i, Elem *e); ɾ����i��λ�õ�Ԫ��
	void ListTraverse();	// void ListTraverse(List *list); �������Ա�
private:
	T* m_pList;
	int m_iSize;	// ����
	int m_iLength;	// ��ǰ��С
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

// ��ע��
template <class T>
int SeqList<T>::LocateElem(T* e) {
	for (int i = 0; i < m_iLength; i++) {
		if (m_pList[i] == *e) {
			return i;
		}
	}
	return -1;
}

// ��ע��
template <class T>
bool SeqList<T>::PriorElem(T* currentElem, T* preElem) {
	int idx = LocateElem(currentElem);
	if (-1 == idx) {// û�ҵ�
		return false;
	}
	if (0 == idx) {// û��ǰ��
		return false;
	}

	*preElem = m_pList[--idx];
	return true;
}

// ��ע��
template <class T>
bool SeqList<T>::NextElem(T* currentElem, T* nextElem) {
	int idx = LocateElem(currentElem);
	if (-1 == idx) {// û�ҵ�
		return false;
	}
	if ((m_iLength - 1) == idx) {// û�к��
		return false;
	}

	*nextElem = m_pList[++idx];
	return true;
}

// ��ע��
template <class T>
bool SeqList<T>::ListInsert(int i, T* e) {

	if (m_iLength == m_iSize) {// �ж���������
		return false;
	}

	if (i < 0 || i > m_iLength) {//  �ж��߼�����
		return false;
	}
	for (int k = m_iLength - 1; k >= i; k--) {//�ƶ�
		m_pList[k + 1] = m_pList[k];
	}

	m_pList[i] = *e;// ����
	m_iLength++;

	return true;
}

// ��ע��
template <class T>
bool SeqList<T>::ListDelete(int i, T* e) {

	if (m_iLength == 0) {// �Ѿ�Ϊ����ֱ�ӷ���
		return false;
	}

	if (i < 0 || i > m_iLength) {//  �ж��߼�����
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
