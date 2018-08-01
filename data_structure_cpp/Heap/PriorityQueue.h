#include"dataStructure.h"
template<typename T>
class PriorityQueue {
private:
	MaxHeap<T> maxHeap;

public:
	PriorityQueue() {
		this->maxHeap =  MaxHeap<T>();
	}

	int getSize() {
		return maxHeap.size();
	}

	bool isEmpty() {
		return maxHeap.isEmpty();
	}

	T getFront() {
		return maxHeap.findMax();
	}

	void enqueue(T e) {
		maxHeap.add(e);
	}

	T dequeue() {
		return maxHeap.extractMax();
	}
};