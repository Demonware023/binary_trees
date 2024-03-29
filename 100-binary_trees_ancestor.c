#include "binary_tress.h"

/**
  * binary_trees_ancestor - Finds lowest common ances. of two nodes.
  * @first: pointer to the first node.
  * @second: pointer to the second node.
  *
  * Return: Pointer to the lowest common ancestor node if the two given nodes.
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *m, *n;
	int depth_m = 0, depth_n = 0;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	for (m = (binary_tree_t *)first; m; m = m->parent)
	{
		depth_m++;
	}
	for (n = (binary_tree_t *)second; n; n = n->parent)
	{
		depth_n++;
	}

	for (; depth_m > depth_n; depth_m--)
	{
		first = first->parent;
	}
	for (; depth_n > depth_m; depth_n--)
	{
		second = second->parent;
	}

	while (first && second)
	{
		if (first == second)
		{
			return ((binary_tree_t *)first);
		}
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
