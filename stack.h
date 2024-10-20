#ifndef STACK_H
#define STACK_H

#include "doubly_linked_list.h"

class Stack : public Doubly_Linked_List
{
    protected:
        node* m_last;

    public:
        Stack();
        ~Stack();
        int* push(const int data);
        void pop();
        void print();
        using Doubly_Linked_List::get_size; // Temp access
};

#endif // STACK_H
