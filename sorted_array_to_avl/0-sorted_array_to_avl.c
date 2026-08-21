#include <stdlib.h>
#include "binary_trees.h"

/**
 * build_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the sorted array
 * @start: Starting index
 * @end: Ending index
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the created subtree, or NULL on failure
 */
static avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int middle;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	node->left = build_avl(array, start, middle - 1, node);
	node->right = build_avl(array, middle + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
