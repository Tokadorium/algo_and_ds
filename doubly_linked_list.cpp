#include <iostream>
#include "doubly_linked_list.h"

Doubly_linked_list::Doubly_linked_list()
{
	m_head = nullptr;
}
Doubly_linked_list::~Doubly_linked_list()
{
	node* current{m_head};

	while(current->next)
	{
		current = current->next;
		delete current->prev;
	}
	delete current;
}

void Doubly_linked_list::print() const
{
	node* current{m_head};

	while(current->next)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
}


int Doubly_linked_list::get_number_of_elements() const;
int Doubly_linked_list::get_value(const int position) const;
node* Doubly_linked_list::get_node_ptr(const int position) const;
int* Doubly_linked_list::add_node_head(const int data);
int* Doubly_linked_list::add_node_tail(const int data);
int* Doubly_linked_list::add_node(const int data);
void Doubly_linked_list::remove_node_head();
void Doubly_linked_list::remove_node_tail();
void Doubly_linked_list::remove_node();
