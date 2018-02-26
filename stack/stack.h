/*
Created by yourenchun
Date: 2018.02.17
*/

/*
class Stack
data members:
	1. capacity of the stack.
	2. top of the stack.
function members:
	1. Constructor, allocate memory. Set capacity and stack top.
	2. Destructor, delete memory. 
	3. is_empty().
	4. is_full().
	5. clear(). set stack top zero to clear stack
	6. length(). get the length of the stack.
	7. push(). push element to stack.
	8. pop(). pull out element from stack
	9. print(). print all elements of the stack.
*/

#include <iostream>
void test();
template<typename T>
class Stack {
private:
	T *data;
	int capacity;
	int top;// begin with zero. if top is -1, it is empty.
public:
	Stack(int capacity);
	~Stack();
	bool is_empty();
	bool is_full();
	void clear();
	int length();
	bool push(T &elem);
	bool pop(T &elem);
	void print();

};
template<typename T>
Stack<T>::Stack(int capacity){
	this->capacity = capacity;
	this->top = -1;
	data = new T[this->capacity];
}

template<typename T>
void Stack<T>::clear() {
	this->length = 0;
	this->top = -1;
}
template<typename T>
Stack<T>::~Stack() {
	delete[](this->data);
}

template<typename T>
bool Stack<T>::is_empty() {
	if (this->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Stack<T>::is_full() {
	if (this->top == (this->capacity - 1)) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
int Stack<T>::length() {
	return this->top + 1;
}

template<typename T>
bool Stack<T>::push(T &elem) {
	if (!this->is_full()) {
		++this->top;
		data[top] = elem;
		return true;
	}
	else {
		return false;
	}
}
template<typename T>
bool Stack<T>::pop(T &elem) {
	if (this->is_empty()) {
		return false;
	}
	else {
		top--;
		elem = data[top];
		return true;
	}
}

template<typename T>
void Stack<T>::print() {
	for (int i = 0;i < this->top +1;i++) {
		std::cout << data[i] << std::endl;
	}
}


void test() {
	Stack<int> *stack = new Stack<int>(10);

	//test push()
	for (int i = 0;i < 11;i++) {
		int elem = i + 1;
		stack->push(elem);
	}

	//test length()
	std::cout << "Length:" << stack->length() << std::endl;
	std::cout << "Is empty:" << stack->is_empty() << std::endl;

	//test print()
	stack->print();

	//test pop()
	int temp;
	for (int i = 0;i < 10;i++) {
		stack->pop(temp);
	}
	//test is_empty()
	std::cout << "Is empty:" << stack->is_empty() << std::endl;
	delete stack;
}