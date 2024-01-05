#include "binary_trees.h"

/**
 * binary_tree_is_leaf -> Write a function that c
 *@node: It's a p
 *Return: node = (NULL)-> (0)
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
		return (0);
	}	return (1);
}
