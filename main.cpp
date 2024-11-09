#include <iostream>
#include "stack.h"

const int LIST_SIZE {10};

int main() {

	Stack stack1;

	for(int i = 0; i < LIST_SIZE; i++) {

		stack1.push(i);
	}

	stack1.print();

	stack1.pop();

	stack1.print();

	std::cout << "Start loop:" << std::endl;

	for(int i = 0; i < 10; i++) {

		std::cout << "i = " << i << std::endl;

		stack1.pop();

		stack1.print();
	}

	stack1.print();

	std::cout << "end" << std::endl;
}
