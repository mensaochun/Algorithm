# include<assert.h>
#include<iostream>
template<typename T>
class LoopQueue {
private:
	T *data;
	int front, tail;
	int capacity;
	int size;          // 有兴趣的同学，在完成这一章后，可以思考一下：
					   // LoopQueue中不声明size，如何完成所有的逻辑？
					   // 这个问题可能会比大家想象的要难一点点：）

public:
	LoopQueue(int capacity) {
		this->capacity = capacity;
		this->data = new T[capacity]; 
		this->front = 0;
		this->tail = 0;
		this->size = 0;
	}

	LoopQueue() {
		this->capacity = 10;
		this->data = new T[this->capacity];
		this->front = 0;
		this->tail = 0;
		this->size = 0;
	}
	~LoopQueue() {
		delete[]this->data;
	}
	int getCapacity() {
		return this->capacity;
	}

	bool isEmpty() {
		return this->front == this->tail;
	}

	int getSize() {
		return this->size;
	}

	void enqueue(T e) {
		// 判断队列是否满，满的话就进行扩容。
		if ((tail + 1) % this->capacity == front) {
			this->resize(getCapacity() * 2);
		}
		this->data[this->tail] = e;
		//添加一个元素之后，通过这种方式来讲tail移位。注意不能直接使用tail++，会出现移到数组前面去的情况。
		this->tail = (this->tail + 1) % this->capacity;
		this->size++;
	}

	T dequeue() {
		// 首先判断是否为空，空的话就不能出队列。
		assert(this->isEmpty() == false);
		T ret = this->data[front];
		// 通过这种方式对front进行重新赋值。注意：不能直接用front++，因为会出现跑到数组前面去的情况。
		front = (front + 1) % this->capacity;
		this->size--;
		if (this->size == this->getCapacity() / 4 && this->getCapacity() / 2 != 0)
			this->resize(this->getCapacity() / 2);
		return ret;
	}

	T getFront() {
		assert(this->isEmpty() != false);
		return data[front];
	}

	void resize(int newCapacity) {

		T *newData = new T[newCapacity];
		for (int i = 0; i < this->size; i++)
			newData[i] = this->data[(i + this->front) % (this->capacity)];
		//delete []data;
		this->data = newData;
		this->front = 0;
		this->tail = this->size;
	}

	/*friend std::ostream & operator<<(std::ostream & out, LoopQueue & loopQueue) {
		for (int i = 0; i < loopQueue.size; i++) {
			int idx = (i + this->front) % this->capacity;
			out << loopQueue.data[idx] << " ";
		}
		out << std::endl;
		return out;
	}*/
	void print() {
		for (int i = 0; i <this->size; i++) {
			int idx = (i + this->front) % this->capacity;
			std::cout << this->data[idx] << " ";
		}
		std::cout << std::endl;
	}
};