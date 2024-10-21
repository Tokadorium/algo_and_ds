#include <iostream>
#include "doubly_linked_list.h"

Doubly_linked_list::Doubly_linked_list() {m_head = nullptr;}

Doubly_linked_list::~Doubly_linked_list() {

	if(m_head) {

		node* current {m_head};

		while(current->next) {

			current = current->next;
			delete current->prev;
		}

		delete current;
	}
}

void Doubly_linked_list::print() const {

	if(m_head) {


	}
}


int Doubly_linked_list::get_size() const {

	if(m_head) {

		int size {1};
		node* current {m_head};

		while(current->next) {

			current = current->next;
			size++;
		}

		return size;

	} else {return 0;}
}

int* Doubly_linked_list::get_value(const int position) const {

	if(m_head) {

		node* current {m_head};

		for(int i = 0; i < position; i++) {

			if(!current->next) {return nullptr;}

			current = current->next;
		}

		return &current->data;

	} else {return nullptr;}
}

node* Doubly_linked_list::get_node(const int position) const;
node* Doubly_linked_list::get_last_node() const;
		
int* Doubly_linked_list::add_node_head(const int data);
int* Doubly_linked_list::add_node_tail(const int data);
int* Doubly_linked_list::add_node(const int data);
void Doubly_linked_list::remove_node_head();
void Doubly_linked_list::remove_node_tail();
void Doubly_linked_list::remove_node();
