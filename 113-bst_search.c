#include "binary_trees.h"

/**
 * bst_search -> Write function to Search Tree
 *@tree: the BST to search
 *@value: It's the value
 *Return: A pointe containing a value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n > value)
		{
			return (bst_search(tree->left, value));

		}	return (bst_search(tree->right, value));
	}	return (NULL);
}
