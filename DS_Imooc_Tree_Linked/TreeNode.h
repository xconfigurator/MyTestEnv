#pragma once
#include <iostream>
using namespace std;

template<class T>
class TreeNode {
	friend ostream& operator<<(ostream& os, const TreeNode<T>& n) {
		//os << n.data << endl;
		os << n.index << "\t" << n.data << endl;
		return os;
	}

public:
	TreeNode() {
		index = 0;
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
	}

	TreeNode(T _data, int _index) {
		data = _data;
		index = _index;
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
	}

	bool operator==(const TreeNode<T>& n) {// .equals()
		return (*this.data == n.data);
	}

	TreeNode<T>* SearchNode(int nodeIndex) {// 与MyTree下的SearchNode同名

		TreeNode<T>* node = NULL;

		if (this->index == nodeIndex) {
			return this;
		}

		if (this->pLeft != NULL) {
			node = this->pLeft->SearchNode(nodeIndex);
		}
		if (node != NULL) {
			return node;
		}

		if (this->pRight != NULL) {
			node = this->pRight->SearchNode(nodeIndex);
		}
		if (node != NULL) {
			return node;
		}

		return node;
	}

	bool DeleteNode() {
		if (this->pLeft != NULL) {
			this->pLeft->DeleteNode();
		}

		if (this->pRight != NULL) {
			this->pRight->DeleteNode();
		}

		if (this->pParent != NULL) {
			if (this->pParent->pLeft == this) {
				this->pParent->pLeft = NULL;
			}

			if (this->pParent->pRight == this) {
				this->pParent->pRight = NULL;
			}
		}

		delete this;
		return true;
	}

	void TreeTraversePreOrder() {
		cout << *this << endl;
		if (this->pLeft != NULL) {
			this->pLeft->TreeTraversePreOrder();
		}
		if (this->pRight != NULL) {
			this->pRight->TreeTraversePreOrder();
		}
	}

	void TreeTraverseInOrder() {
		if (this->pLeft != NULL) {
			this->pLeft->TreeTraverseInOrder();
		}
		cout << *this << endl;
		if (this->pRight != NULL) {
			this->pRight->TreeTraverseInOrder();
		}
	}

	void TreeTraversePostOrder() {
		if (this->pLeft != NULL) {
			this->pLeft->TreeTraversePostOrder();
		}
		if (this->pRight != NULL) {
			this->pRight->TreeTraversePostOrder();
		}
		cout << *this << endl;
	}

	T data;
	int index;
	TreeNode<T>* pLeft;
	TreeNode<T>* pRight;
	TreeNode<T>* pParent;
};
