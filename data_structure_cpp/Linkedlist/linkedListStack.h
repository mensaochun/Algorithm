#include<iostream>
#include"linkedList.h"
template<typename T>
class LinkedListStack {
private:
	LinkedList<T> *list;
public:
	LinkedListStack() {
		this->list = new LinkedList<T>();
	}
	int getSize() {
		return list->getSize();
	}

	bool isEmpty() {
		return list->isEmpty();
	}

	void push(T e) {
		list->addFirst(e);
	}

	T pop() {
		return list->removeFirst();
	}

	T peek() {
		return list->getFirst();
	}

	void print() {
		std::cout << this->list;
	}
};
