#include<assert.h>
#include <iostream>
template<typename T>
class Array{
private:
	T *data;
	int capacity;
	int size;
	
public:
	// 构造函数，传入数组的容量capacity构造Array
	Array(int capacity) {
		this->capacity = capacity;
		this->data = new T[capacity];
		this->size = 0;
	}

	// 无参数的构造函数，默认数组的容量capacity=10
	Array() {
		this->Array(10);
	}

	~Array() {
		delete[]this->data;
	}

	// 获取数组的容量
	int getCapacity() {
		return this->capacity;
	}

	// 获取数组中的元素个数
	int getSize() {
		return this->size;
	}

	// 返回数组是否为空
	bool isEmpty() {
		return this->size == 0;
	}

	// 在index索引的位置插入一个新元素e
	void add(int index,T e) { 

		assert(this->size < capacity);
		assert(index >= 0 && index <= this->size);
		for (int i = this->size ; i > index; i--) {
			this->data[i] = this->data[i - 1];
		}
		/*for (int i = this->size - 1; i >= index; i--)
			this->data[i + 1] = this->data[i];*/

		this->data[index] = e;
		this->size++;
	}

	// 向所有元素后添加一个新元素
	void addLast(T e) {
		this->add(this->size, e);
	}

	// 在所有元素前添加一个新元素
	void addFirst(T e) {
		this->add(0, e);
	}

	// 获取index索引位置的元素
	T get(int index) {
		assert(index >= 0 && index < size);
		return this->data[index];
	}

	// 修改index索引位置的元素为e
	void set(int index, T e) {
		assert(index >= 0 && index < size);
		this->data[index] = e;
	}

	// 查找数组中是否有元素e
	bool contains(T e) {
		for (int i = 0; i < size; i++) {
			if (this->data[i] == e) {
				return true;
			}	
		}
		return false;
	}

	// 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
	int find(T e) {
		for (int i = 0; i < size; i++) {
			if (data[i]==e)
				return i;
		}
		return -1;
	}

	// 从数组中删除index位置的元素, 返回删除的元素
	T remove(int index) {
		assert(index >= 0 && index < size);
		T ret = this->data[index];
		for (int i = index; i < size-1; i++)
			data[i] = data[i+1];
		/*for (int i = index + 1; i < size; i++)
			data[i - 1] = data[i];*/
		this->size--;
		return ret;
	}

	// 从数组中删除第一个元素, 返回删除的元素
	T removeFirst() {
		return this->remove(0);
	}

	// 从数组中删除最后一个元素, 返回删除的元素
	T removeLast() {
		return this->remove(this->size - 1);
	}

	// 从数组中删除元素e
	void removeElement(T e) {
		int index = this->find(e);
		if (index != -1)
			this->remove(index);
	}
	friend std::ostream & operator<<(std::ostream & out, Array & array) {
		for (int i = 0; i < array.size; i++) {
			out << array.data[i] << " ";
		}
		out << std::endl;
		return out;
	}
};
