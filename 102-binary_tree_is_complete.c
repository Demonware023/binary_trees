#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t **queue;
	size_t size = 1024;
	size_t front = 0, back = 0;
	int is_complete = 1, no_child = 0;

	queue = malloc(size * sizeof(*queue));
	if (queue == NULL)
		return (0);

	queue[back] = (binary_tree_t *)tree;
	back++;

	while (front < back)
	{
		binary_tree_t *node = queue[front];
		front++;

		if (node->left != NULL)
		{
			if (no_child)
			{
				is_complete = 0;
				break;
			}
			if (back >= size)
			{
				size *= 2;
				queue = realloc(queue, size * sizeof(*queue));
				if (queue == NULL)
					return (0);
			}
			queue[back] = node->left;
			back++;
		}
		else
		{
			no_child = 1;
		}

		if (node->right != NULL)
		{
			if (no_child)
			{
				is_complete = 0;
				break;
			}
			if (back >= size)
			{
				size *= 2;
				queue = realloc(queue, size * sizeof(*queue));
				if (queue == NULL)
					return (0);
			}
			queue[back] = node->right;
			back++;
		}
		else
		{
			no_child = 1;
		}
	}

	free(queue);
	return (is_complete);
}
