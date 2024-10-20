#include <iostream>
#include "stack.h"

int main()
{
    Stack stack;

    stack.print();

    for(int i = 0; i < 10; i++)
    {
        stack.push(i);
    }

    stack.print();
    std::cout << "Size: " << stack.get_size() << std::endl;

    stack.pop();

    stack.print();
    std::cout << "Size: " << stack.get_size() << std::endl;

    stack.pop();

    stack.print();
    std::cout << "Size: " << stack.get_size() << std::endl;
}
