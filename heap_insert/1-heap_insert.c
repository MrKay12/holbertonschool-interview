#include "binary_trees.h"

#define MAX_QUEUE 1024

/**
 * swap - Swaps two node values
 * @a: First node
 * @b: Second node
 */
void swap(heap_t *a, heap_t *b)
{
	int tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *queue[MAX_QUEUE], *parent, *new;
	int front = 0, rear = 0;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	queue[rear++] = *root;

	while (front < rear)
	{
		parent = queue[front++];

		if (parent->left == NULL)
		{
			new = binary_tree_node(parent, value);
			if (new == NULL)
				return (NULL);
			parent->left = new;
			break;
		}
		queue[rear++] = parent->left;

		if (parent->right == NULL)
		{
			new = binary_tree_node(parent, value);
			if (new == NULL)
				return (NULL);
			parent->right = new;
			break;
		}
		queue[rear++] = parent->right;
	}

	while (new->parent != NULL && new->n > new->parent->n)
	{
		swap(new, new->parent);
		new = new->parent;
	}

	return (new);
}
