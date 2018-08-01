#include"dataStructure.h"
#include<iostream>
#include<vector>
int main() {
	ArrayQueue<int> *queue = new ArrayQueue<int>;
	for (int i = 0; i < 10; i++) {
		queue->enqueue(i);
		queue->print();
		if (i % 3 == 2) {
			queue->dequeue();
			queue->print();
		}
	}
}