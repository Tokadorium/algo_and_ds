#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H

class Circular_array {

	private:

		int* m_array;
		int m_size_current;
		int m_size_max;
		int m_front;
		int m_rear;

		bool is_empty();
		bool is_full();

	public:

		// Constructors
		Circular_array(int size);
		~Circular_array();

		// Methods
		int* add_element(int data);
		int* remove_element();

		int get_size();
		int print();
};

#endif // CIRCULAR_ARRAY_H
