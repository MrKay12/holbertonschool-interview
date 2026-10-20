
#include "search_algos.h"
#include <stdio.h>

/**
 * print_subarray - Prints the subarray being searched
 * @array: Pointer to the first element of the subarray
 * @size: Number of elements to print
 */
void print_subarray(int *array, size_t size)
{
	printf("Searching in array: ");
	print_array_recursive(array, size);
	printf("\n");
}

/**
 * print_array_recursive - Prints array elements recursively
 * @array: Pointer to the first element
 * @size: Number of elements remaining
 */
void print_array_recursive(int *array, size_t size)
{
	if (size == 0)
		return;

	printf("%d", *array);
	if (size > 1)
		printf(", ");
	print_array_recursive(array + 1, size - 1);
}

/**
 * advanced_binary_recursive - Searches recursively for the first occurrence
 * @array: Pointer to the current subarray
 * @size: Number of elements in the current subarray
 * @value: Value to search for
 * @offset: Starting index in the original array
 *
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary_recursive(int *array, size_t size, int value,
			      size_t offset)
{
	size_t mid;

	if (size == 0)
		return (-1);

	print_subarray(array, size);
	mid = size / 2;

	if (array[mid] >= value)
	{
		if (array[mid] == value)
		{
			if (mid == 0 || array[mid - 1] < value)
				return ((int)(offset + mid));
		}
		return (advanced_binary_recursive(array, mid, value, offset));
	}

	return (advanced_binary_recursive(array + mid + 1,
					  size - mid - 1,
					  value, offset + mid + 1));
}

/**
 * advanced_binary - Searches for the first occurrence of a value
 * @array: Pointer to the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, size, value, 0));
}
