#include"BST.h"
#include<iostream>
#include<vector>
#include<algorithm>
int main() {
		
		BST<int>* bst = new BST<int>();
		int n = 10;
		//生成随机数组，数组的数量大小为n*repetios,数组里面有重复元素，重复次数是repetions。
		std::vector<int> randomVec;
		for (int i = 0; i < n; i++) {
			randomVec.push_back(i);
		}
		// 将生成的数组打乱
		std::random_shuffle(randomVec.begin(),randomVec.end());

		// 往树中添加元素
		for (int i = 0; i < n; i++) {
			bst->add(randomVec[i]);
			std::cout << randomVec[i] << " ";
		}
		std::cout << std::endl;

		//移除最小值
		for (int i = 0; i < n; i++) {
			int rem=bst->removeMin();
			std::cout << rem << " ";
		}
		std::cout << std::endl;

		// 往树中添加元素
		for (int i = 0; i < n; i++) {
			bst->add(randomVec[i]);
			std::cout << randomVec[i] << " ";
		}
		std::cout << std::endl;
		//移除最小大值
		for (int i = 0; i < n; i++) {
			int rem = bst->removeMax();
			std::cout << rem << " ";
		}
}
