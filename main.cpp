#include <iostream>
#include "doubly_linked_list.h"

const int SIZE{10};

int main()
{
    Doubly_Linked_List list;

    list.print_list();

    std::cout << "Size: " << list.get_size() << std::endl;

    for(int i = 0; i < SIZE; i++)
    {
        list.add_node(i, list.get_size());
    }

    list.print_list();
}
