#include"linkedListStack.h"
#include<iostream>
int main() {

	Array<int> arr(20);
	for (int i = 0; i < 10; i++) {
		arr.addLast(i);
	}
		
	std::cout << arr;

	arr.add(1, 100);
	std::cout << arr;

	arr.addFirst(-1);
	std::cout << arr;
	// [-1, 0, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9]

	arr.remove(2);
	std::cout << arr;

	arr.removeElement(4);
	std::cout << arr;

	arr.removeFirst();
	std::cout << arr;

}
