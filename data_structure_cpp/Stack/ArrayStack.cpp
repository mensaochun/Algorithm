#include"dataStructure.h"
#include<iostream>
int main() {
	ArrayStack<int> stack;
	for (int i = 0; i < 5; i++) {
		stack.push(i);
	}
	std::cout << stack;
	stack.pop();
	std::cout << stack;

}