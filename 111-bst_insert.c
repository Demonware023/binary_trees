#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    if (tree == NULL)
        return (NULL);

    current = *tree;
    parent = NULL;

    /* Search for the appropriate place to insert the new node */
    while (current != NULL)
    {
        if (value == current->n)
            return (NULL); /* Value already exists, so ignore */

        parent = current;

        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    /* Create a new node with the given value */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* If parent is NULL, the tree is empty */
    if (parent == NULL)
        *tree = new_node;
    else if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}
