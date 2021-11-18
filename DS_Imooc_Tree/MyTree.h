/****************************************************/
/*
��C++ʵ��
����汾
Visual Studio 2017
@since 2016/12/22
@author liuyang
@update 2017/9/14
*/
/****************************************************/
#ifndef _MY_TREE_
#define _MY_TREE_


/*
�γ�Ҫ��������Ļ�������
1. ���Ĵ���������
2. ���нڵ������
3. ���нڵ�������ɾ��
4. ���нڵ�ı���
*/
class MyTree {
public:
	MyTree(int size, int* pRoot);		// ����
	~MyTree();							// ����
	int* SearchNode(int nodeIndex);		// ��������Ѱ�ҽڵ�
	bool AddNode(int nodeIndex, int direction, int* pNode);		// ��ӽڵ�
	bool DeleteNode(int nodeIndex, int* pNode);					// ɾ���ڵ�
	void TreeTraverse();				// �����ڵ�
private:
	int* m_pTree;
	int m_iSize;
	bool isIndexOutofBound(int nodeIndex);			// �±��Ƿ�Խ��
	bool isNodeNull(int nodeIndex);					// �ڵ��Ƿ�Ϊ��
};

#endif
