#include "binary_trees.h"

/**
 * binary_tree_depth -> Write a measures
 *@tree: It's a pointer to the node
 *Return: tree = (NULL)
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);

}
