#include<vector>
#include<iostream>
using std::vector;
template<typename T>
class ArrayQueue{
private:
	vector<T> *array;
public:
	ArrayQueue() {
		array = new vector<T>;
	}
	~ArrayQueue() {
		delete array;
	}

	int getSize() {
		return array->size();
	}

	bool isEmpty() {
		return array->empty();
	}

	int getCapacity() {
		return array->capacity();
	}

	void enqueue(T e) {
		array->push_back(e);
	}

	T dequeue() {
		// vector删除第一个元素需要通过迭代器，具体参考：https://zhidao.baidu.com/question/1174443676189215499.html
		// T e = array[0];这样是不行的，暂时没找到原因。
 		T e = array->front();
		array->erase(this->array->begin());
		return e;
	}

	T getFront() {
		return array->front();
	}

	//friend std::ostream & operator<<(std::ostream & out, ArrayQueue & arrayQueue) {
	//	//c++使用 vector指针访问vector元素时，不能简单的类似于c中数组和指针的方式。需要使用迭代器。
	//	//参考：https://blog.csdn.net/fao9001/article/details/75006369
	//	for (vector<T>::iterator it = arrayQueue.array->begin(); it != arrayQueue.array->end(); it++) {
	//		out << *it << " ";
	//	}
	//	out << std::endl;
	//	return out;
	//}
	void print() {
		//以下方法是不行的。不支持泛型，暂时不知道为什么。
		/*for (vector<T>::iterator it = array->begin(); it != array->end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;*/
		for (int i = 0; i < array->size(); i++) {
			//注意这里需要用解引用
			std::cout << (*array)[i]<<" ";
		}
		std::cout << std::endl;
	}
};