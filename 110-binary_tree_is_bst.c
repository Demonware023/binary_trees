#include "binary_trees.h"

/**
 * is_bst_util - Checks if a binary tree is a valid BST (utility function).
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value a node in the tree can have.
 * @max: The maximum value a node in the tree can have.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */

int bst_check(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);
    if (tree->n < min || tree->n > max)
        return (0);
    return (bst_check(tree->left, min, tree->n - 1) && bst_check(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (bst_check(tree, INT_MIN, INT_MAX));
}
