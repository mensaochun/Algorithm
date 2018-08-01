#include<assert.h>
#include <iostream>
template<typename T>
class Node {
public:
	T e;
	Node<T>* next;
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
	Node<T> *dummyHead;
	int size;
public:
	LinkedList() {
		this->dummyHead = new Node<T>();
		this->size = 0;
	}
	~LinkedList() {
		int size = this->size;
		for (int i = 0; i < size; i++) {
			this->removeFirst();
		}
	}

	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}


	// 在链表的index(0-based)位置添加新的元素e
	// 在链表中不是一个常用的操作，练习用：）
	void add(int index, T e) {
		assert(index >= 0 && index <= size);
		if (index == 0) {
			this->dummyHead->next=new Node<T>(e,this->dummyHead->next);
			this->size++;
		}
		else {
			Node<T> *prev = this->dummyHead;
			for (int i = 0; i < index ; i++) {
				prev = prev->next;
			}
			/*Node<T> *node=new Node<T>(e);
			node->next = prev->next;
			prev->next = node;*/
			prev->next = new Node<T>(e, prev->next);
			this->size++;
		}
	}
	void addFirst(T e) {
		this->add(0, e);
	}

	// 在链表末尾添加新的元素e
	void addLast(T e) {
		this->add(this->size, e);
	}

	// 获得链表的第index(0-based)个位置的元素
	// 在链表中不是一个常用的操作，练习用：）
	T get(int index) {

		assert(index >= 0 && index < size);

		Node<T> *cur = this->dummyHead->next;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		return cur->e;
	}

	// 获得链表的第一个元素
	T getFirst() {
		return this->get(0);
	}

	// 获得链表的最后一个元素
	T getLast() {
		return this->get(size - 1);
	}

	// 修改链表的第index(0-based)个位置的元素为e
	// 在链表中不是一个常用的操作，练习用：）
	void set(int index, T e) {
		assert(index >= 0 && index < size);
		Node<T> *cur = dummyHead->next;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		cur->e = e;
	}

	// 查找链表中是否有元素e
	bool contains(T e) {
		Node<T> *cur = this->dummyHead->next;
		while (cur != nullptr) {
			if (cur->e == e) {
				return true;
			}
			cur = cur->next;
		}
		return false;
	}
	// 从链表中删除index(0-based)位置的元素, 返回删除的元素
	// 在链表中不是一个常用的操作，练习用：）
	T remove(int index) {
		assert(index >= 0 && index < size);
		Node<T> *prev = this->dummyHead;
		for (int i = 0; i < index; i++) {
			prev = prev->next;
		}
		Node<T> *retNode = prev->next;
		T e = retNode->e;
		prev->next = retNode->next;
		delete retNode;
		this->size--;

		return e;
	}

	// 从链表中删除第一个元素, 返回删除的元素
	T removeFirst() {
		return remove(0);
	}

	// 从链表中删除最后一个元素, 返回删除的元素
	T removeLast() {
		return remove(size - 1);
	}

	// 从链表中删除元素e，此时假定链表中
	void removeElement(T e) {

		Node<T> *prev = this->dummyHead;
		while (prev->next != nullptr) {
			if (prev->next->e == e) {
				break;
			}
			prev = prev->next;
		}

		if (prev.next != null) {
			Node<T> *delNode = prev->next;
			prev->next = delNode->next;
			delete delNode;
			this->size--;
		}
	}
	friend std::ostream & operator<<(std::ostream & out, LinkedList & linkedList) {
		Node<T> *cur = linkedList.dummyHead->next;
		while (cur != nullptr) {
			out << cur->e<<" ";
			cur = cur->next;
		}
		out << std::endl;
		return out;
	}
};

