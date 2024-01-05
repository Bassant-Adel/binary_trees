#include "binary_trees.h"

/**
 * binary_tree_postorder -> Write a function
 *@tree: It's a pointer
 *@func: It's a pointer
 *Return: (tree)
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);

		binary_tree_postorder(tree->right, func);

		func(tree->n);
	}
}
