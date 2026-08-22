#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *current, *end;

	if (list == NULL)
		return (NULL);

	prev = list;
	current = list->express;

	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		if (current->n >= value)
			break;

		prev = current;
		current = current->express;
	}

	if (current == NULL)
	{
		end = prev;

		while (end->next != NULL)
			end = end->next;
	}
	else
	{
		end = current;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, end->index);

	current = prev;

	while (current != NULL && current->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		if (current->n == value)
			return (current);

		if (current->n > value)
			return (NULL);

		current = current->next;
	}

	return (NULL);
}
