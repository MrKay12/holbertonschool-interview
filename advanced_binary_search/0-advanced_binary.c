
#include "search_algos.h"
#include <stdio.h>

/**
 * print_array_recursive - Prints an array recursively
 * @array: Pointer to the first element
 * @size: Number of elements to print
 */
void print_array_recursive(int *array, size_t size)
{
	if (size == 0)
		return;

	printf("%d", array[0]);
	if (size > 1)
		printf(", ");
	print_array_recursive(array + 1, size - 1);
}

/**
 * print_subarray - Prints the subarray being searched
 * @array: Pointer to the first element
 * @size: Number of elements to print
 */
void print_subarray(int *array, size_t size)
{
	printf("Searching in array: ");
	print_array_recursive(array, size);
	printf("\n");
}

/**
 * advanced_binary_recursive - Searches for the first occurrence
 * @array: Pointer to the current subarray
 * @size: Number of elements in the current subarray
 * @value: Value to search for
 * @offset: Starting index in the original array
 *
 * Return: Index of the first occurrence, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t size, int value,
			      size_t offset)
{
	size_t mid;
	int result;

	if (size == 0)
		return (-1);

	print_subarray(array, size);
	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0)
			return ((int)(offset + mid));

		result = advanced_binary_recursive(array, mid, value, offset);
		if (result != -1)
			return (result);

		return ((int)(offset + mid));
	}

	if (array[mid] > value)
		return (advanced_binary_recursive(array, mid + 1,
						   value, offset));

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
 * Return: Index of the first occurrence, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, size, value, 0));
}
