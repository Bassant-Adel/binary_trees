#include "binary_trees.h"

/**
 * binary_tree_is_full -> Write function tha
 *@tree: It's a pointer
 *Return: tree = (NULL)
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);

	}	return (is_full_recursive(tree));
}

/**
 * is_full_recursive -> ary tree is full
 *@tree: It's a pointer to root node
 *Return: tree = (NULL)
 */

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
		{
			return (0);
		}
	}	return (1);
}
