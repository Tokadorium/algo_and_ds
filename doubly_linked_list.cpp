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

		node* current {m_head};

		while(current) {

			std::cout << current->data << " ";
			current = current->next;
		}
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

int* Doubly_linked_list::get_value(const int position) const {return &get_node(position)->data;}

node* Doubly_linked_list::get_node(const int position) const {

	if(m_head) {

		node* current {m_head};

		for(int i = 0; i < position; i++) {

			if(!current->next) {return nullptr;}

			current = current->next;
		}

		return current;

	} else {return nullptr;}
}

node* Doubly_linked_list::get_node_tail() const {

	if(m_head) {

		node* current {m_head};

		while(current->next) {

			current = current->next;
		}

		return current;
	
	} else {return nullptr;}
}
		
int* Doubly_linked_list::add_node_head(const int data) {

	if(!m_head) {

		m_head = new node;

		m_head->prev = nullptr;
		m_head->data = data;
		m_head->next = nullptr;

		return &m_head->data;

	} else {return nullptr;}
}

int* Doubly_linked_list::add_node_tail(const int data) {

	if(m_head) {

		node* last_node;
		node* new_node;

		last_node = get_node_tail();
		
		new_node = new node;
		last_node->next = new_node;

		new_node->prev = last_node;
		new_node->data = data;
		new_node->next = nullptr;

		return &new_node->data;
	
	} else {return nullptr;}
}
		
int* Doubly_linked_list::add_node(const int position, const int data);
void Doubly_linked_list::remove_node_head();
void Doubly_linked_list::remove_node_tail();
void Doubly_linked_list::remove_node();
