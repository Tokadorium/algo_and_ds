#include <iostream>
#include "stack.h"

Stack::Stack() : Doubly_Linked_List(), m_last(nullptr) {};
Stack::~Stack() {};

int* Stack::push(const int data)
{
    return add_node(data, get_size());
}

void Stack::pop()
{
    std::cout << "Popped value: " << return_node()->data
            << " from position: " << get_size() - 1 << std::endl;

    remove_node(get_size() - 1);
}

void Stack::print()
{
    Doubly_Linked_List::print();
}
