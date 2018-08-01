#include<vector>
#include<iostream>
#include"dataStructure.h"
using namespace std;
int main() {
	MaxHeap<int> *maxHeap = new MaxHeap<int>();
	std::vector<int> nums = { 5,3,8,9,2,7,4,2,7,8,3,10 };
	for (int i = 0; i < 12; i++) {
		maxHeap->add(nums[i]);
	}
	maxHeap->print();
	for (int i = 0; i < 12; i++) {
		int max = maxHeap->extractMax();
		std::cout << max << " ";
	}
	maxHeap->print();

}