#include "stack.h"

int stack_test(const int value)
{
    Stack stack;

    stack.print();

    for(int i = 0; i < value; i++)
    {
        stack.push(i);
    }

    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
