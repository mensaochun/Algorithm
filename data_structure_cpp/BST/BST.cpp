#include"dataStructure.h"
#include<iostream>
#include<vector>
int main() {

	BST<int> bst;
	int nums[]= { 5, 3, 6, 8, 4, 2 };
	for (int i = 0; i < 6; i++) {
		bst.add(nums[i]);
	}
	/////////////////
	//      5      //
	//    /   \    //
	//   3    6    //
	//  / \    \   //
	// 2  4     8  //
	/////////////////
	bst.preOrder();
	std::cout << std::endl;
	bst.inOrder();
	std::cout << std::endl;
	bst.postOrder();
	std::cout << std::endl;
}