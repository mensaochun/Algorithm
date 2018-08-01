#include<vector>
#include<iostream>
#include"dataStructure.h"
using namespace std;
int main() {
	std::vector<string> words = { "hello","nice","to","meet","you","hello","nice" };
	LinkedListMap<string, int>* map = new LinkedListMap<string, int>();
	for (int i = 0; i < 7;i++) {
		if (map->contains(words[i])) {
			map->set(words[i], map->get(words[i]) + 1);
		}
		else {
			map->add(words[i], 1);
		}
	}
	map->print();
	std::cout << std::endl;
	map->remove("hello");
	map->print();
}