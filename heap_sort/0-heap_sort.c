
#include "sort.h"

/**
 * sift_down - Moves an element down to restore the max heap property
 * @array: Array to sort
 * @size: Size of the heap
 * @root: Index of the root element
 */
void sift_down(int *array, size_t size, size_t root)
{
	size_t largest, left, right;
	int temp;

	while (root < size / 2)
	{
		left = 2 * root + 1;
		right = left + 1;
		largest = root;

		if (left < size && array[left] > array[largest])
			largest = left;
		if (right < size && array[right] > array[largest])
			largest = right;
		if (largest == root)
			break;

		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (!array || size < 2)
		return;

	i = size / 2;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i);
	}

	i = size;
	while (i > 1)
	{
		i--;
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, i, 0);
	}
}
