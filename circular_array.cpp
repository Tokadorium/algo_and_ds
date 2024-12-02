#include <iostream>
#include "circular_array.h"

// Private
// bool Circular_array::is_empty() {

// 	return ((m_rear == m_front) == -1) ? true : false;
// }

bool Circular_array::is_full() {

	return ((m_rear + 1) % m_size_max) == m_front ? true : false;
}

// Constructors
Circular_array::Circular_array(int size) {

	if(!(m_array = new int[size])) {return;}
	
	m_size_current = 0;
	m_size_max = size;
	m_front = -1;
	m_rear = -1;
}

Circular_array::~Circular_array() {

	if(m_array) {delete m_array;}
}

// Public
// Methods
int* Circular_array::add_element(int data) {

	if(is_full()) {m_rear = (m_rear % m_size_max) + 1;}

	m_front = (m_front % m_size_max) + 1;
	int* value_ptr = m_array + (m_front % m_size_max);
	*value_ptr = data;

	return value_ptr;
}

int* Circular_array::remove_element();

int Circular_array::get_size();
int Circular_array::print();
