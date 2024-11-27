#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H

class Circular_array {

	private:

		int* m_table;
		int max_size;
		int current_size;

		int* insert_at_begining();
		int* insert_at_end();

		int* remove_from_begining();
		int* remove_from_end();

	public:

		Circular_array(int max_size);
		~Circular_array();

		int get_current_size();

		void print();
		void peek(int position);

		int* insert_at_position(int position);
		int* remove_from_position(int position);
};

#endif // CIRCULAR_ARRAY_H
