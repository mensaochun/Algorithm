# include "linkedListStack.h"

int main() {
	int opCount = 100000;
	LinkedListStack<int> *linkedListStack = new LinkedListStack<int>();
	for (int i = 0; i < opCount; i++) {
		linkedListStack->push(i);
	}
	for (int i = 0; i < opCount; i++) {
		linkedListStack->pop();
	}
	std::cout << "Done!" << std::endl;
	// ��ʵ���ʱ��ȽϺܸ��ӣ���ΪLinkedListStack�а��������new����

}