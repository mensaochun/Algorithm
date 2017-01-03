/*

˼·��
1.�����������鴢�棬����Ԫ��Ϊ0��ʾ�˴�û�нڵ㡣
2.ʹ����ģ�塣

���ݳ�Ա��
1.T *TreePtr,����ָ�룬���ڿ����ڴ�
2.int capacity,�����С

��Ա������
1.TreeArray��int size�������캯���������ڴ棬��ʼ��capacity������Ԫ�س�ʼ��Ϊ0 
2.~TreeArray(),���������������ڴ�
3.bool addNode(int index,int direciton,T element)
	��ӽڵ㡣
	ʵ�֣�
	a.�ж���index��2*index+1��2*index+2�Ƿ��������±귶Χ֮��;
			direction��ֵ��
			index��2*index+1��2*index+2��Ӧ������Ԫ���Ƿ�Ϊ0��
	b.���������Ľڵ������Һ�����ӽڵ�element
4.bool searchNode(int index)
	Ѱ�������±�Ϊindex��Ԫ�أ�������ֵ
5.T *searchNode(int index)
	searchNode()��������,Ѱ�������±�Ϊindex��Ԫ�أ�������ָ��
6.bool deleteNode(int index)
	�����������Ľڵ�ɾ��
7.T* deleteNode(int index);
	����deleteNode��������
8.void traverse();
	����������

�����Ķ�����ʵ�����£�

               2��0��
       8��1��          3��2��
7��3��    0��4�� 1��5��    6��6��


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
	cout << "��������" << endl;
}

template<typename T>
bool TreeArray<T>::addNode(int index, int direction, T element)
{
	if (index < -1 || index >= this->capacity||treePtr[index]==0)
		return false;

	//index=-1���ڴ������ڵ㣬direction=-1˵��ûָ�����Һ���
	if (index == -1 && treePtr[0] == 0&&direction==-1)
	{
		treePtr[0] = element;
		return true;
	}
	
	//��������
	if (direction == 0)
		if (2 * index + 1 < 0 || 2 * index + 1 >= capacity|| treePtr[2 * index + 1] != 0)
			return false;
		else
		{
			treePtr[2 * index + 1] = element;
			return true;
		}
	
	//�����Һ���		
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

