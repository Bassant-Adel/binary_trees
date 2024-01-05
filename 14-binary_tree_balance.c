#include "binary_trees.h"

/**
 * binary_tree_balance -> Write at measures
 *@tree: It's a pointer to balance factor
 *Return: tree = (NULL)
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	}	return (0);
}

/**
 * binary_tree_height -> Writeasures
 *@tree: It's a poithe height
 *Return: tree = (NULL)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t le = 0, ri = 0;

		le = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		ri = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((le > ri) ? le : ri);

	}	return (0);
}
