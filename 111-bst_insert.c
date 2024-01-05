#include "binary_trees.h"

/**
 * bst_insert -> inserts a value in a Binary Search Tree
 *@tree: It's a double insert the value
 *@value: to store in the node to be inserted
 *Return: A pointer
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *le, *ri;

	if (tree != NULL)
	{
		le = *tree;
		if (le == NULL)
		{
			ri = binary_tree_node(le, value);
			if (ri == NULL)
			{
				return (NULL);
			}	return (*tree = ri);
		}
		if (value < le->n)
		{
			if (le->left != NULL)
			{
				return (bst_insert(&le->left, value));
			}	ri = binary_tree_node(le, value);

			if (ri == NULL)
			{
				return (NULL);
			}	return (le->left = ri);
		}

		if (value > le->n)
		{
			if (le->right != NULL)
			{
				return (bst_insert(&le->right, value));
			}	ri = binary_tree_node(le, value);
			if (ri == NULL)
			{
				return (NULL);
			}	return (le->right = ri);		}
	}	return (NULL);
}
