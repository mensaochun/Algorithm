#pragma once
#include<iostream>
#include<assert.h>
template<typename T>
class Node {
public:
	T e;
	Node *left;
	Node *right;

public:
	Node(T e) {
		this->e = e;
		left = nullptr;
		right = nullptr;
	}

};

template<typename T>
class BST {
private:
	Node<T> *root;
	int size;
public:
	BST() {
		this->root = nullptr;
		this->size = 0;
	}
	~BST() {
		this->delTree(this->root);
	}
	void delTree(Node<T> *node) {
		if (node = nullptr) {
			return;
		}
		delTree(node->left);
		delTree(node->right);
		std::cout << "delete node " << node->e;
		delete node;
		node = nullptr;
	}

	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}

	void add(T e) {
		this->root = this->add(this->root, e);
	}
	// 看二分搜索树中是否包含元素e，这里假设没有重复元素。
	bool contains(T e) {
		return this->contain(this->root, e);
	}
	// 二分搜索树的前序遍历
	void preOrder() {
		this->preOrder(this->root);
	}
	// 二分搜索树的中序遍历
	void inOrder() {
		this->inOrder(this->root);
	}
	// 二分搜索树的后序遍历
	void postOrder() {
		this->postOrder(this->root);
	}


public:
	// 向以node为根的二分搜索树中插入元素e，递归算法
	// 返回插入新节点后二分搜索树的根

	Node<T>* add(Node<T> *node, T e) {
		if (node == nullptr) {
			this->size++;
			return new Node<T>(e);
		}
		if (e<node->e) {
			node->left = add(node->left, e);
		}
		else if (e > node->e) {
			node->right = add(node->right, e);
		}
		return node;
	}
	// 看以node为根的二分搜索树中是否包含元素e, 递归算法
	bool contain(Node<T> *node, T e) {
		if (node == nullptr) {
			return false;
		}
		if (node->e == e) {
			return true;
		}
		else if (e<node->e) {
			return contain(node->left, e);
		}
		else {
			return contain(node->right, e);
		}

	}
	// 前序遍历以node为根的二分搜索树, 递归算法
	void preOrder(Node<T> *node) {
		if (node == nullptr) {
			return;
		}
		std::cout << node->e << std::endl;
		preOrder(node->left);
		preOrder(node->right);
	}
	// 中序遍历以node为根的二分搜索树, 递归算法
	void inOrder(Node<T> *node) {
		if (node == nullptr) {
			return;
		}
		inOrder(node->left);
		std::cout << node->e << std::endl;
		inOrder(node->right);
	}
	// 后序遍历以node为根的二分搜索树, 递归算法
	void postOrder(Node<T> *node) {
		if (node == nullptr) {
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->e << std::endl;
	}

	// 寻找二分搜索树的最小元素
	T minimum() {
		assert(this->size > 0);
		Node<T> *minNode = minimum(this->root);
		return minNode->e;
	}

	// 返回以node为根的二分搜索树的最小值所在的节点
	Node<T>* minimum(Node<T>* node) {
		if (node->left == nullptr) {
			return node;
		}
		return minimum(node->left);
	}

	// 寻找二分搜索树的最大元素
	T maximum() {
		assert(this->size > 0);
		Node<T> *maxNode = maximum(this->root);
		return maxNode->e;
	}

	// 返回以node为根的二分搜索树的最大值所在的节点
	Node<T>* maximum(Node<T> *node) {
		if (node->right == nullptr) {
			return node;
		}
		return maximum(node->right);
	}

	// 从二分搜索树中删除最小值所在节点, 返回最小值
	T removeMin() {
		T ret = this->minimum();
		this->root = this->removeMin(this->root);
		return ret;
	}

	// 删除掉以node为根的二分搜索树中的最小节点
	// 返回删除节点后新的二分搜索树的根
	Node<T>* removeMin(Node<T>* node) {

		if (node->left == nullptr) {
			Node<T>* rightNode = node->right;
			delete node;
			this->size--;
			return rightNode;
		}

		node->left = this->removeMin(node->left);
		return node;
	}

	// 从二分搜索树中删除最大值所在节点
	T removeMax() {
		T ret = this->maximum();
		this->root = this->removeMax(this->root);
		return ret;
	}

	// 删除掉以node为根的二分搜索树中的最大节点
	// 返回删除节点后新的二分搜索树的根
	Node<T>* removeMax(Node<T> *node) {

		if (node->right == nullptr) {
			Node<T>* leftNode = node->left;
			delete node;
			this->size--;
			return leftNode;
		}
		node->right =this-> removeMax(node->right);
		return node;
	}
	// 从二分搜索树中删除元素为e的节点
	void remove(T e) {
		this->root = remove(this->root, e);
	}

	// 删除掉以node为根的二分搜索树中值为e的节点, 递归算法
	// 返回删除节点后新的二分搜索树的根
	Node<T>* remove(Node<T>* node, T e) {
		if (node == nullptr) {
			return nullptr;
		}
		if (e< node->e) {
			node->left = this->remove(node->left, e);
			return node;
		}
		else if (e> node->e) {
			node->right = this->remove(node->right, e);
			return node;
		}
		else {   // e.compareTo(node.e) == 0

				 // 待删除节点左子树为空的情况
			if (node->left == nullptr) {
				Node<T>* rightNode = node->right;
				delete node;
				this->size--;
				return rightNode;
			}

			// 待删除节点右子树为空的情况
			if (node->right == nullptr) {
				Node<T>* leftNode = node->left;
				delete node;
				this->size--;
				return leftNode;
			}

			// 待删除节点左右子树均不为空的情况

			// 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
			// 用这个节点顶替待删除节点的位置
			Node<T>* successor = this->minimum(node->right);
			//删除右子树的最小节点，返回根。
			successor->right =this-> removeMin(node->right);
			successor->left = node->left;
			delete node;
			return successor;
		}
	}

};