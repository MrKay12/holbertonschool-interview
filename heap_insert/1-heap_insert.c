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
 * find_parent - Finds insertion parent
 * @root: Root of heap
 *
 * Return: Parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *queue[MAX_QUEUE], *parent;
	int front = 0, rear = 0;

	queue[rear++] = root;
	while (front < rear)
	{
		parent = queue[front++];
		if (parent->left == NULL || parent->right == NULL)
			return (parent);
		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}
	return (NULL);
}

/**
 * heapify - Restores max heap order
 * @node: Inserted node
 *
 * Return: Final position of inserted value
 */
heap_t *heapify(heap_t *node)
{
	while (node->parent != NULL && node->n > node->parent->n)
	{
		swap(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 *
 * Return: Pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_parent(*root);
	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	return (heapify(new));
}
