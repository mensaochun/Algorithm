#include<vector>
#include<algorithm>
#include<iostream>
#include<assert.h>
using std::vector;
template<typename T>
//这里使用vector作为动态数组使用
class MaxHeap{
private:
	vector<T> data;

public:
	MaxHeap(int capacity) {
		this->data = vector<T>(capacity);
	}

	MaxHeap() {
		this->data = vector<T>();
	}

	// 返回堆中的元素个数
	int size() {
		return this->data.size();
	}

	// 返回一个布尔值, 表示堆中是否为空
	bool sEmpty() {
		return this->data.empty();
	}

	// 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
	// 这里的索引是从0开始的
	int parent(int index) {
		assert(index > 0);
		return (index - 1) / 2;
	}

	// 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
	int leftChild(int index) {
		return index * 2 + 1;
	}

	// 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
	int rightChild(int index) {
		return index * 2 + 2;
	}

	// 向堆中添加元素
	void add(T e) {
		this->data.push_back(e);
		this->siftUp(this->data.size() - 1);
	}

	void siftUp(int k) {
		//索引大于0，父亲节点比它大，则交换。
		while (k > 0 && this->data[this->parent(k)]<this->data[k] ) {
			std::swap(this->data[k], this->data[this->parent(k)]);
			k = parent(k);
		}
	}

	// 找堆中的最大元素
	T findMax() {
		assert(this->data.size() > 0);
		return this->data[0];
	}

	// 取出堆中最大元素
	T extractMax() {

		T ret =this-> findMax();
		std::swap(this->data[0], this->data[this->data.size() - 1]);
		this->data.pop_back();
		this->siftDown(0);
		return ret;
	}

	void siftDown(int k) {

		while (this->leftChild(k) < this->data.size()) {
			int j = this->leftChild(k); // 在此轮循环中,data[k]和data[j]交换位置
			if (j + 1 <this-> data.size() && this->data[j + 1]>this->data[j]) {
				j++;
				// data[j] 是 leftChild 和 rightChild 中的最大值
			}
			if (this->data[k]>=this->data[j])
				break;

			std::swap(this->data[k], this->data[j]);
			k = j;
		}
	}
	void print() {
		int size = this->data.size();
		for (int i = 0; i<size; i++) {
			std::cout << this->data[i] << " ";
		}
		std::cout << std::endl;
	}
};
