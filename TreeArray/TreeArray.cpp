/*
              2（0）
      8（1）          3（2）
7（3）    0（4） 1（5）    6（6）


*/

#include"TreeArray.h"
#include<iostream>
using namespace std;
int main()
{
	//TreeArray实例化
	TreeArray<int> *tree = new TreeArray<int>(10);
	
	//添加节点
	tree->addNode(-1,-1,2);
	tree->addNode(0,0,8);
	tree->addNode(0,1,3);
	tree->addNode(1,0,7);
	tree->addNode(1,1,0);
	tree->addNode(2,0,1);
	tree->addNode(2,1,6);
	cout << "添加数组完毕" << endl ;

	//遍历数组
	cout<<"遍历数组:";
	tree->traverse();

	//寻找数组中的有效节点
	cout << "寻找数组中的第4个有效节点:";
	int *p1=tree->searchNode(3);
	if (p1 != NULL)
		cout << *p1 << endl;
	else
		cout << "没有节点" << endl;
	
	//寻找数组中无效节点
	cout << "寻找数组中第5个无效节点:";
	int *p2 = tree->searchNode(4);
	if (p2 != NULL)
		cout << *p2 << endl;
	else
		cout << "没有节点" << endl;

	//删除节点
	int temp;
	tree->deleteNode(2, temp);
	cout<< "删除的第3个节点是" << temp << endl;
	cout << "删除之后的二叉树：";
	tree->traverse();

	//销毁数组
	tree->~TreeArray();
}