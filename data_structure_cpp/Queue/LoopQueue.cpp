#include"dataStructure.h"
#include<iostream>
#include<vector>
int main() {

	LoopQueue<int> *queue = new LoopQueue<int>();
	for (int i = 0; i < 20; i++) {
		queue->enqueue(i);
		queue->print();
		//std::cout << queue;

		if (i % 3 == 2) {
			queue->dequeue();
			queue->print();
			//std::cout << queue;
		}
	}
}