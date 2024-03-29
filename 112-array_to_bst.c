#include "binary_trees.h"

/**
 * bst_free_tree - Frees the memory allocated for a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to be freed.
 */
void bst_free_tree(bst_t *tree)
{
    if (tree == NULL)
        return;

    /* Free the left and right subtrees */
    bst_free_tree(tree->left);
    bst_free_tree(tree->right);

    /* Free the current node */
    free(tree);
}

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;
    size_t i;

    if (array == NULL || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (bst_insert(&root, array[i]) == NULL)
        {
            /* If insertion fails, free the memory allocated so far */
            bst_free_tree(root);
            return (NULL);
        }
    }

    return (root);
}
