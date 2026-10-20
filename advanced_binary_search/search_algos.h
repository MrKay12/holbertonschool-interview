
#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

int advanced_binary(int *array, size_t size, int value);
int advanced_binary_recursive(int *array, size_t size, int value,
			      size_t offset);
void print_subarray(int *array, size_t size);

#endif