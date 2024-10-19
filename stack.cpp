#include "stack.h"

Stack::Stack() : Doubly_Linked_List(), m_last(nullptr) {};
Stack::~Stack() {};

int* Stack::push(const int data)
{
    return add_node(data, get_size());
}

void Stack::pop()
{
    remove_node(get_size());
}
