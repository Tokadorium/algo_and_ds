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
}
