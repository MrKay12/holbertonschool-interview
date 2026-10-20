
#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t heap_size, size_t total_size,
	       size_t root);

#endif
