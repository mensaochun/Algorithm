/*

思路：
1.二叉树用数组储存，数组元素为0表示此处没有节点。
2.使用类模板。

数据成员：
1.T *TreePtr,数组指针，用于开辟内存
2.int capacity,数组大小

成员函数：
1.TreeArray（int size），构造函数：申请内存，初始化capacity，数组元素初始化为0 
2.~TreeArray(),析构函数：销毁内存
3.bool addNode(int index,int direciton,T element)
	添加节点。
	实现：
	a.判定：index，2*index+1和2*index+2是否在数组下标范围之内;
			direction的值；
			index，2*index+1和2*index+2对应的数组元素是否为0；
	b.符合条件的节点的左或右孩子添加节点element
4.bool searchNode(int index)
	寻找数组下标为index的元素，返回其值
5.T *searchNode(int index)
	searchNode()函数重载,寻找数组下标为index的元素，返回其指针
6.bool deleteNode(int index)
	将满足条件的节点删除
7.T* deleteNode(int index);
	重载deleteNode（）函数
8.void traverse();
	遍历二叉树

构建的二叉树实例如下：

               2（0）
       8（1）          3（2）
7（3）    0（4） 1（5）    6（6）


*/


#include<iostream>
using namespace std;
template<typename T>
class TreeArray
{
private:
	int capacity;
	T *treePtr;

public:
	TreeArray(int size);
	~TreeArray();
	bool addNode(int index, int direction, T element);
	bool deleteNode(int index,T &element);
	T* deleteNode(int index);
	bool searchNode(int index, T &element);
	T* searchNode(int index);
	void traverse();
};

template<typename T>
TreeArray<T>::TreeArray(int size)
{
	this->capacity = size;
	treePtr = new T[capacity];
	for (int i = 0; i <this->capacity; i++)
	{
		treePtr[i] = 0;
	}
}

template<typename T>
TreeArray<T>::~TreeArray()
{
	delete[]treePtr;
	cout << "销毁数组" << endl;
}

template<typename T>
bool TreeArray<T>::addNode(int index, int direction, T element)
{
	if (index < -1 || index >= this->capacity||treePtr[index]==0)
		return false;

	//index=-1用于创建根节点，direction=-1说明没指定左右孩子
	if (index == -1 && treePtr[0] == 0&&direction==-1)
	{
		treePtr[0] = element;
		return true;
	}
	
	//插入左孩子
	if (direction == 0)
		if (2 * index + 1 < 0 || 2 * index + 1 >= capacity|| treePtr[2 * index + 1] != 0)
			return false;
		else
		{
			treePtr[2 * index + 1] = element;
			return true;
		}
	
	//插入右孩子		
	if(direction==1)
		if (2 * index + 2 < 0 || 2 * index + 2 >= capacity||treePtr[2 * index + 2] != 0)
			return false;
		else
		{
			treePtr[2 * index + 2] = element;
			return true;
		}
}

template<typename T>
bool TreeArray<T>::deleteNode(int index,T &element)
{
	if (index < 0 || index >= capacity || treePtr[index] == 0)
		return false;
	else
	{
		element = treePtr[index];
		treePtr[index] = 0;
		return true;
	}
}

template<typename T>
T* TreeArray<T>::deleteNode(int index)
{
	if (index < 0 || index >= capacity || treePtr[index] == 0)
		return NULL;
	else
	{
		T *p = &treePtr[index];
		treePtr[index] = 0;
		return p;
	}
		
}

template<typename T>
T* TreeArray<T>::searchNode(int index)
{
	if (index < 0 || index >= capacity || treePtr[index] == 0)
		return NULL;
	else
		return &treePtr[index];
}

template<typename T>
bool TreeArray<T>::searchNode(int index,T &element)
{
	if (index < 0 || index >= capacity || treePtr[index] == 0)
		return false;
	else
	{
		element = treePtr[index];
		return true;
	}
}

template<typename T>
void TreeArray<T>::traverse()
{
	for (int i = 0; i < this->capacity; i++)
		cout << treePtr[i] << " ";
	cout << endl;
}

