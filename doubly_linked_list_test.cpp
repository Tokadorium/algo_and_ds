#include <iostream>
#include "doubly_linked_list.h"

int doubly_linked_list_test(int value)
{
    Doubly_Linked_List list;

    list.print();

    std::cout << "Size: " << list.get_size() << std::endl;

    for(int i = 0; i < value; i++)
    {
        list.add_node(i, list.get_size());
    }

    list.print();

    int e_number = 4;

    std::cout << "Element: " << e_number <<
                " Data: " << *list.get_element(e_number)
                << std::endl;

    list.remove_node(3);

    std::cout << "Element: " << e_number <<
                " Data: " << *list.get_element(e_number)
                << std::endl;

    list.print();

    return 0;
}

