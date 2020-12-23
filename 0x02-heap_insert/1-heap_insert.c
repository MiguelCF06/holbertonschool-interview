#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * h_size - function to take the size in a tree.
 * @root: The pointer to the root of the tree.
 * Return: The size of the tree.
 */

int h_size(binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + h_size(root->left) + h_size(root->right));
}


/**
 * order - function to insert in correct order.
 * @root: pointer to the root of the tree.
 * @value: value of the node to insert.
 * @index: index of the current node.
 * @len: new position to insert the new node.
 * Return: The pointer to the inserted node.
 */

heap_t *order(binary_tree_t *root, int value, int index, int len)
{
	heap_t *new;

	if (root == NULL)
		return (NULL);

	if (index + 1 == len / 2)
	{
		if (len % 2 == 1)
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
		else
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
	}
	new = order(root->left, value, 2 * index + 1, len);
	if (new)
		return (new);
	return (order(root->right, value, 2 * index + 2, len));
}

/**
 * h_swap - Function to change positions.
 * @parent: pointer to the parent node.
 * @new: pointer to the new node.
 * @value: value of the node to insert.
 * Return: pointer to the new position.
 */

heap_t *h_swap(heap_t *parent, heap_t *new, int value)
{
	new->n = parent->n;
	parent->n = value;
	new = parent;

	return (new);
}

/**
 * heap_insert - Inserts a new value in a Max Binary Heap.
 * @root: The pointer to the root of the tree.
 * @value: The value of the node to insert.
 * Return: The pointer to the inserted node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = order(*root, value, 0, h_size(*root) + 1);

	while (new->parent != NULL && new->n > new->parent->n)
		new = h_swap(new->parent, new, value);

	return (new);
}
