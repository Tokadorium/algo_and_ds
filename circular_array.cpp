#include <iostream>
#include "circular_array.h"

Circular_array::Circular_array(int size) {m_table = new int[size];}

Circular_array::~Circular_array() {

if(m_table) {delete m_table;}

}


int* Circular_array::insert_at_begining();
int* Circular_array::insert_at_end();

int* Circular_array::remove_from_begining();
int* Circular_array::remove_from_end();


int Circular_array::get_current_size() {return current_size;}

void Circular_array::print() {

	for(int i = 0; i < current_size; i++) {

		std::cout << *(m_table + i) << " ";
	}

	std::cout << std::endl;
}

void Circular_array::peek(int position) {

	if(position > 0 && position < current_size) {

		std::cout << *(m_table + position) << std::endl;

	} else {

		std::cerr << "Out of bounds" << std::endl;
	}
}

int* Circular_array::insert_at_position(int position);
int* Circular_array::remove_from_position(int position);
