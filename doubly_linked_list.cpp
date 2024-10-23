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

		std::cout << std::endl;
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
		
int* Doubly_linked_list::add_node(const int position, const int data) {

	if(position == 0) {return add_node_head(data);}

	else if(position == get_size()) {return add_node_tail(data);}

	else {

		node* current;
		node* new_node;

		current = get_node(position);

		new_node = new node;

		current->next->prev = new_node;
		current->next = new_node;
		
		new_node->prev = current;
		new_node->data = data;
		new_node->next = current->next;	

		return &new_node->data;
	}
}

void Doubly_linked_list::remove_node_head() {

	if(m_head->next) {

		node* new_head;

		new_head = m_head->next;
		new_head->prev = nullptr;

		delete m_head;

		m_head = new_head;
	
	} else if(m_head) {

		delete m_head;
		m_head = nullptr;
	}
}

void Doubly_linked_list::remove_node_tail() {

	if(m_head) {
		node* new_last_node;
		new_last_node = get_node(get_size() - 1);

		delete get_node_tail();

		new_last_node->next = nullptr;
	}
}

void Doubly_linked_list::remove_node(const int position) {

	if(position == 0) {remove_node_head();}

	else if(position == get_size()) {remove_node_tail();}

	else {
		
		node* current;

		current = get_node(position);

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
	}
}
