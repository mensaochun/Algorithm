# include "linkedList.h"
int main() {
	LinkedList<int> linkedList;
	for (int i = 0; i < 5; i++) {
		linkedList.addFirst(i);
		std::cout << linkedList;
	}
	linkedList.add( 2, 666);
	std::cout << linkedList;

	linkedList.remove(2);
	std::cout << linkedList;
	linkedList.removeFirst();
	std::cout << linkedList;
	linkedList.removeLast();
	std::cout << linkedList;

}