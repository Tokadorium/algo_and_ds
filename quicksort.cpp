int* quicksort(int* array_start, int array_size) { // function expects continous array in memory bc caching

	if(!array_start || array_size < 1) {return nullptr;}

	int* pivot = (array_start + (array_size / 2)); // = choose_pivot(); For now its approx. middle of array.

	// for now i will create another array bc memory is abundant now but later
	// it may be fun to shift existing array in memory without rearranging it.
	
	int* sorted_array = new int[array_size] {};

	for(;;) {

		for(int i = 0; i < (pivot - array_start); i++) {

			if(*(array_start + i) > *pivot) {

				*(sorted_array + (pivot - array_start)) = *(array_start + i);
			}
		}

		for(int i = (pivot - array_start); i < array_size; i++) {

			if(*(array_start + i) < *pivot) {

			}
		}
	}
	
}

