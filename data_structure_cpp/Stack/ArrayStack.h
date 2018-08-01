#include "array.h"
#include<iostream>
template<typename T>
class ArrayStack{
private:
	Array<T> *array;
public:
	ArrayStack(int capacity) {
		array = new Array<T>(capacity);
	}

	ArrayStack() {
		array = new Array<T>();
	}

	int getSize() {
		return array->getSize();
	}

	bool isEmpty() {
		return array->isEmpty();
	}

	int getCapacity() {
		return array->getCapacity();
	}

	void push(T e) {
		array->addLast(e);
	}

	T pop() {
		return array->removeLast();
	}

	T peek() {
		return array->getLast();
	}

	friend std::ostream & operator<<(std::ostream & out, ArrayStack & arrayStack) {
		for (int i = 0; i < arrayStack.array->getSize(); i++) {
			out << arrayStack.array->get(i) << " ";
		}
		out << std::endl;
		return out;
	}
};
