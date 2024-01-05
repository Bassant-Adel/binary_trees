#include "binary_trees.h"

/**
 * binary_tree_inorder -> Write a func
 *@tree: It's a pointer to the r
 *@func: It's a pointer to a f
 *Return: (tree or func)
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);

		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
