#include<assert.h>
template<typename T>
class Node {
public:	
	T e;
	T* next;
public:
	Node() {
		this->next = nullptr;
	}
	Node(T e) {
		this->e = e;
		this->next = nullptr;
	}
	Node(T e, Node<T> *node) {
		this->e = e;
		this->next = node;
	}
};

template<typename T>
class LinkedList {
private:
	Node<T> head;
	int size;
public:
	LinkedList() {
		this->head = nullptr;
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}

	void addFist(T e) {
		/*Node<T> *node = new Node<T>(e);
		node->next = this->head;
		this->head = node;*/

		this->head = new Node<T>(e, this->head);
		this->size++;
	}

	// 在链表的index(0-based)位置添加新的元素e
	// 在链表中不是一个常用的操作，练习用：）
	void add(int index, T e) {
		assert(index >= 0 && index <= size);
		if (index == 0) {
			this->addFist(e);
		}
		else {
			Node<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->next;
			}
			Node<T> *node=new Node<T>(e);
			node->next = prev->next;
			prev->next = node;
			this->size++;
		}
	}

	// 在链表末尾添加新的元素e
	void addLast(T e) {
		this->add(this->size, e);
	}

};