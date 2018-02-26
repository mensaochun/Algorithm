#include<iostream>
template<typename T>
class Node {
public:
	T data;
	Node<T> *next;
	
	Node() {
		this->next = NULL;
	}
	Node(T &data) {
		this->data = data;
		this->next = NULL;
	}
	/*
	void print() {
		std::cout << this->data << std::endl;
	}
	*/
};

template<typename T>
class LinkList {
private:
	Node<T> *head;
	int length;
public:
	// init head.
	LinkList();
	// delete head.
	~LinkList();
	// clear all nodes.
	void clear();
	int get_length();
	void insert_head(T &elem);
	void insert_tail(T &elem);
	bool get_elem(int i,T &elem);
	int locate_elem(T &elem);
	bool insert_elem(int i, T &elem);
	bool delete_elem(int i);	
	void print();
};

void test();

template<typename T>
LinkList<T>::LinkList() {
	// Note: head has no data.
	this->head = new Node<T>();
	this->length = 0;
}

template<typename T>
LinkList<T>::~LinkList() {
	this->clear();
	delete this->head;
}

template<typename T>
void LinkList<T>::insert_tail(T &elem) {
	Node<T> *new_node = new Node<T>(elem);
	Node<T> *temp = this->head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = new_node;
	(this->length)++;
	// how to return bool value?
	//return true;
}

template<typename T>
void LinkList<T>::insert_head(T &elem) {
	//TODO: how to return bool value?
	Node<T> *new_node =new Node<T>(elem);
	new_node->next = this->head->next;
	this->head->next = new_node;
	(this->length)++;
}

template<typename T>
bool LinkList<T>::get_elem(int i, T &elem) {
	if (this->head->next == NULL||i>this->length) {
		return false;
	}
	int count = 0;
	Node<T> *temp = this->head->next;
	while (temp) {
		count++;
		if (count == i) {
			elem = temp->data;
			return true;
		}
		temp = temp->next;
	}
}

template<typename T>
int LinkList<T>::locate_elem(T &elem) {
	// Require: no same elems.
	// If not exist nodes, how to deal with?
	if (this->head->next == NULL) {
		// TODO
		return 0;
	}
	int count = 0;
	Node<T> *temp = this->head->next;
	while (temp->next) {
		count++;
		if (temp->data == elem) {
			return count;
		}
		temp = temp->next;
	}
	if (temp->data == elem) {
		return count;
	}
}

template<typename T>
bool LinkList<T> ::insert_elem(int i, T &elem) {
	// Check: 1<=i<=length
	if (i>this->length||i<1) {
		return false;
	}
	Node<T> *new_node =new Node<T>(elem);
	Node<T> *temp = this->head;
	for (int count = 1;count < i ;count++) {
		temp = temp->next;
	}
	// temp is (i-1)th node.
	new_node->next = temp->next;
	temp->next = new_node;
	return true;
}

template<typename T>
bool LinkList<T>::delete_elem(int i) {
	
}

template<typename T>
void LinkList<T>::clear() {
	Node<T> *temp = this->head->next;
	while (temp) {
		delete temp;
		temp = temp->next;
	}
}

template<typename T>
int LinkList<T>::get_length() {
	return this->length;
}

template<typename T>
void LinkList<T>::print() {
	Node<T> *temp = this->head->next;
	while (temp) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void test() {
	LinkList<int> *list = new LinkList<int>();
	int arr_1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr_2[5] = { 11,12,13,14,15 };
	int var_1 = 100;
	// test insert_tail()
	for (int i = 0;i < 10;i++) {
		list->insert_tail(arr_1[i]);
	}
	// test insert_head()
	for (int i = 0;i < 5;i++) {
		list->insert_head(arr_2[i]);
	}
	// test insert()
	list->insert_elem(6, var_1);

	// test print()
	list->print();

	//test get_elem()
	int var_2;
	list->get_elem(3,var_2);
	std::cout << "3th elem is:" << var_2 << std::endl;
	
	//test locate_elem()
	int var_3 = 9;

	//test delete_elem()
	int loc=list->locate_elem(var_3);
	std::cout << "9 is locating in " << loc << std::endl;
}