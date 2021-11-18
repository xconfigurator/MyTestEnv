/****************************************************/
/*
树C++实现
数组版本
Visual Studio 2017
@since 2016/12/22
@author liuyang
@update 2017/9/14
*/
/****************************************************/
#ifndef _MY_TREE_
#define _MY_TREE_


/*
课程要求：完成树的基本操作
1. 树的创建和销毁
2. 树中节点的搜索
3. 树中节点的添加与删除
4. 树中节点的遍历
*/
class MyTree {
public:
	MyTree(int size, int* pRoot);		// 创建
	~MyTree();							// 销毁
	int* SearchNode(int nodeIndex);		// 根据索引寻找节点
	bool AddNode(int nodeIndex, int direction, int* pNode);		// 添加节点
	bool DeleteNode(int nodeIndex, int* pNode);					// 删除节点
	void TreeTraverse();				// 遍历节点
private:
	int* m_pTree;
	int m_iSize;
	bool isIndexOutofBound(int nodeIndex);			// 下标是否越界
	bool isNodeNull(int nodeIndex);					// 节点是否为空
};

#endif
