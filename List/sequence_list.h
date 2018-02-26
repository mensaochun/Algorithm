/*
Created by yourenchun
2018.2.20
*/

/*
TODO

*/
#include<iostream>
template<typename T>
class SequenceList {
private:
	T *data;
	int capacity;
	int length;
public:
	SequenceList(int capacity);
	~SequenceList();
	void clear();
	bool is_full();
	bool is_empty();
	int length();
	bool get_elem(int index,T &elem);
	int locate_elem(T &elem);
	bool prev_elem(T &prev_elm,T &cur_elem);
	bool next_elem(T &prev_elm, T &cur_elem);
	bool insert(int i, T &elem);
	bool del(int i, T&elem);
	void print();
};

template<typename T>
SequenceList<T>::SequenceList(int capacity) {
	this->capacity = capacity;
	data = new T[this->capacity];
	this->length = 0;
}
template<typename T>
SequenceList<T>::~SequenceList() {
	delete[]data;
}

template<typename T>
void SequenceList<T>::clear() {
	this->length = 0;
}

template<typename T>
bool SequenceList<T>::is_full() {
	if (this->length == this->capacity) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool SequenceList<T>::is_empty() {
	if (this->length == 0) {
		return true;
	}
	else {
		return false;
	}
}
template<typename T>
int SequenceList<T>::length() {
	return this->length;
}

template<typename T>
bool SequenceList<T>::get_elem(int index,T &elem) {
	// 1.bound check:index must be 0~length
	// 2.check is_empty()
	if (this->is_empty()) {
		return false;
	}
	else if (index<0 || index>(this->capacity - 1)) {
		return false;
	}else {
		elem = data[index];
		return true;
	}
}

template<typename T>
int SequenceList<T>::locate_elem(T &elem) {b
	// 1.check is_empty()?
	// 2.if no the elem, how to deal with?
}

