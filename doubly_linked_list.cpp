#include <iostream>
#include "doubly_linked_list.h"



Doubly_Linked_List::Doubly_Linked_List() : m_head(nullptr) {};
Doubly_Linked_List::~Doubly_Linked_List()
{
    node* current{m_head};

    while(current)
    {
        current = current->next;
        delete current->prev;
    }
}

void Doubly_Linked_List::print() const
{
    node* current{m_head};

    if(!current)
    {
        std::cerr << "No data" << std::endl;
        return;
    }

    while(current)
    {
        std::cout << current->data << " ";

        current = current->next;
    }

    std::cout << std::endl;
}

node* Doubly_Linked_List::return_node(int position) const
{
    node* current{m_head};

    if(position == -1)
    {
        while(current->next)
        {
            current = current->next;
        }

        return current;
    }
    else
    {
        for(int i = 0; i < position; i++)
        {
            if(!current)
            {
                std::cerr << "Position out of bounds" << std::endl;
                return nullptr;
            }

            current = current->next;
        }

        return current;
    }
}

int Doubly_Linked_List::get_size() const
{
    int size{0};
    node* current{m_head};

    while(current)
    {
        size++;
        current = current->next;
    }

    return size;
}

int* Doubly_Linked_List::add_node(const int data, const int position)
{
    if(position < 0)
    {
        std::cerr << "Position must be greater than 0" << std::endl;
        return nullptr;
    }
    else if(!position)
    {
        m_head = new node;
        m_head->prev = nullptr;
        m_head->next = nullptr;
        m_head->data = data;
        return &m_head->data;
    }
    else if(position == get_size())
    {
        node* new_node = new node;

        new_node->prev = return_node();
        return_node()->next = new_node;
        new_node->data = data;
        return &new_node->data;
    }
    else
    {
        node* current{return_node(position)};

        if(!current)
        {
            return nullptr;
        }

        node* new_node = new node;

        new_node->prev = current;
        new_node->next = current->next;
        new_node->data = data;

        current->next->prev = new_node;
        current->next = new_node;

        return &new_node->data;
    }
}

void Doubly_Linked_List::remove_node(const int position)
{
    if(position < 0)
    {
        std::cerr << "Position must be greater than 0" << std::endl;
        return;
    }
    else if(!position)
    {
        delete m_head;
        return;
    }
    else if(position == get_size() - 1)
    {
        return_node(get_size() - 2)->next = nullptr;
        delete return_node();
        return;
    }
    else
    {
        node* current{return_node(position)};

        if(!current)
        {
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        return;
    }
}

int* Doubly_Linked_List::get_element(const int position) const
{
    node* value{return_node(position)};
    
    if(!value)
    {
        std::cerr << "Element doesn't exist." << std::endl;
        return nullptr;
    }

    return &value->data;
}
