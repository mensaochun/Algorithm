#include<iostream>
#include<assert.h>
template<typename K,typename V>
class Node {
public:
	K key;
	V value;
	Node *next;

	Node(K key, V value, Node* next) {
		this->key = key;
		this->value = value;
		this->next = next;
	}

	Node(K key, V value) {
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}

	Node() {
		this->next = nullptr;
	}
};

template<typename K,typename V>
class LinkedListMap{
private:
	Node<K,V>* dummyHead;
	int size;
public:
	LinkedListMap() {
		this->dummyHead = new Node<K,V>();
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}

	bool isEmpty() {
		return this->size == 0;
	}

	Node<K,V>* getNode(K key) {
		Node<K,V>* cur = this->dummyHead->next;
		while (cur != nullptr) {
			if (cur->key == key) {
				return cur;
			}
			cur = cur->next;
		}
		return nullptr;
	}

	bool contains(K key) {
		return this->getNode(key) != nullptr;
	}

	V get(K key) {
		Node<K,V>* node = this->getNode(key);
		if( node == nullptr){
			return NULL;//TODO
		}
		else {
			return node->value;
		}
	}

	void add(K key, V value) {
		Node<K,V>* node = this->getNode(key);
		if (node == nullptr) {
			this->dummyHead->next = new Node<K,V>(key, value, this->dummyHead->next);
			this->size++;
		}
		else {
			node->value = value;
		}	
	}

	void set(K key, V newValue) {
		Node<K,V>* node = this->getNode(key);
		assert(node != nullptr);
		node->value = newValue;
	}

	V remove(K key) {

		Node<K,V>* prev = this->dummyHead;
		while (prev->next != nullptr) {
			if (prev->next->key == key) {
				break;
			}
			prev = prev->next;
		}

		if (prev->next != nullptr) {
			Node<K,V>* delNode = prev->next;
			V delVal = delNode->value;
			prev->next = delNode->next;
			delete delNode;
			this->size--;
			return delVal;
		}

		return NULL; //TODO
	}

	void print() {
		Node<K, V>* cur = this->dummyHead->next;
		if (cur == nullptr) {
			std::cout << "The map is empty.";
		}
		while (cur != nullptr) {
			std::cout << (char *)cur->key.c_str() << ":" << cur->value << " ";
			cur=cur->next;
		}
	}
};
