#include <iostream>
#include "doubly_linked_list.h"

const int LIST_SIZE {10};

int main() {

	Doubly_linked_list list1;

	list1.print();

	for(int i = 0; i < LIST_SIZE; i++) {

		list1.add_node(i, i);
	}

	list1.print();

	list1.remove_node(0);

	list1.print();

	list1.remove_node(4);

	list1.print();

	list1.add_node(list1.get_size(), 10);

	list1.add_node(0, -1);

	list1.print();

	list1.add_node(4, 666);

	list1.print();

	std::cout << "Size: " << list1.get_size() << std::endl;
}
