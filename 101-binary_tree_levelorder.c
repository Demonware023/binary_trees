#include "binary_trees.h"

/**
  * binary_tree_levelorder - Goes through a binary tree level in order transversal.
  * tree: pointer to the root node of the tree to tranvserse.
  * func: pointer to a function to call for each node. The value in the/
  * node must be passed a parameter to this function.

  * Return: tree or func is NULL, do nothing.
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_t **queue;
	size_t size = 1024;
	size_t front = 0, back = 0;

	queue = malloc(size * sizeof(*queue));
	if (queue == NULL)
	{
		return;
	}

	queue[back] = (binary_tree_t *)tree;
	back++;

	while (front < back)
	{
		binary_tree_t *node = queue[front];
		front++;
		func(node->n);

		if (node->left != NULL)
		{
			if (back >= size)
			{
				size *= 2;
				queue = realloc(queue, size * sizeof(*queue));
				if (queue == NULL)
				{
					return;
				}
			}
			queue[back] = node->left;
			back++;
		}
		if (node->right != NULL)
		{
			if (back >= size)
			{
				size *= 2;
				queue = realloc(queue, size * sizeof(*queue));
				if (queue == NULL)
				{
					return;
				}
			}
			queue[back] = node->right;
			back++;
		}
	}
	free(queue);
}
