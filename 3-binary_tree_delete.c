#include "binary_trees.h"

/**
 * binary_tree_delete -> Write a function that delete
 *@tree: It's a pointer elete
 *Return: tree
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);

		binary_tree_delete(tree->right);

		free(tree);
	}
}
