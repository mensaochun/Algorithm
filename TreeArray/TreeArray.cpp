/*
              2��0��
      8��1��          3��2��
7��3��    0��4�� 1��5��    6��6��


*/

#include"TreeArray.h"
#include<iostream>
using namespace std;
int main()
{
	//TreeArrayʵ����
	TreeArray<int> *tree = new TreeArray<int>(10);
	
	//��ӽڵ�
	tree->addNode(-1,-1,2);
	tree->addNode(0,0,8);
	tree->addNode(0,1,3);
	tree->addNode(1,0,7);
	tree->addNode(1,1,0);
	tree->addNode(2,0,1);
	tree->addNode(2,1,6);
	cout << "����������" << endl ;

	//��������
	cout<<"��������:";
	tree->traverse();

	//Ѱ�������е���Ч�ڵ�
	cout << "Ѱ�������еĵ�4����Ч�ڵ�:";
	int *p1=tree->searchNode(3);
	if (p1 != NULL)
		cout << *p1 << endl;
	else
		cout << "û�нڵ�" << endl;
	
	//Ѱ����������Ч�ڵ�
	cout << "Ѱ�������е�5����Ч�ڵ�:";
	int *p2 = tree->searchNode(4);
	if (p2 != NULL)
		cout << *p2 << endl;
	else
		cout << "û�нڵ�" << endl;

	//ɾ���ڵ�
	int temp;
	tree->deleteNode(2, temp);
	cout<< "ɾ���ĵ�3���ڵ���" << temp << endl;
	cout << "ɾ��֮��Ķ�������";
	tree->traverse();

	//��������
	tree->~TreeArray();
}