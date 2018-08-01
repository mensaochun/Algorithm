#include"BST.h"
#include<iostream>
#include<vector>
#include<algorithm>
int main() {
		
		BST<int>* bst = new BST<int>();
		int n = 10;
		int repetitions = 2;

		//生成随机数组，数组的数量大小为n*repetios,数组里面有重复元素，重复次数是repetions。
		std::vector<int> randomVec;
		for (int i = 0; i < repetitions; i++) {
			for (int j = 0; j < n; j++) {
				randomVec.push_back(j);
			}
		}
		// 将生成的数组打乱
		std::random_shuffle(randomVec.begin(),randomVec.end());

		//在二分搜索树中添加随机数字
		for (int i = 0; i < repetitions*n; i++) {
			bst->add(randomVec[i]);
		}

		//// order数组中存放[0...n)的所有元素
		std::vector<int> order;
		for (int i = 0; i < n; i++) {
			order.push_back(i);
		}
		// 打乱order数组的顺序
		std::random_shuffle(order.begin(),order.end());

		// 乱序删除[0...n)范围里的所有元素
		for (int i = 0; i < n; i++) {
			if (bst->contains(order[i])) {
				bst -> remove(order[i]);
				std::cout << "After remove " << order[i] << ", size = " << bst->getSize() << std::endl;
			}
		}
		// 最终整个二分搜索树应该为空
		std::cout << bst->getSize() << std::endl;
}
