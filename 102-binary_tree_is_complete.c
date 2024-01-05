#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete -> Write checks trees
 *@tree: It's root node of the tree to check
 *Return: (tree) = (0)
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	size_t le_hei, ri_hei;
	binary_tree_t *le, *ri;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);
	le = tree->left;
	ri = tree->right;
	le_hei = binary_tree_height(le);
	ri_hei = binary_tree_height(ri);

	if (le_hei == ri_hei)
	{
		if (binary_tree_is_perfect(le) && binary_tree_is_complete(ri))
			return (1);
	}

	else if (le_hei == ri_hei + 1)
	{
		if (binary_tree_is_complete(le) && binary_tree_is_perfect(ri))
			return (1);

	}	return (0);
}

/**
 * binary_tree_is_leaf -> checks if a node is a leaf
 *@node: It's a pointer to check
 *Return: node = (leaf)-> (1)
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
		return (0);
	}	return (1);
}

/**
 * binary_tree_height -> height of a binary tree
 *@tree: It's tree to measure the height
 *Return: tree = (NULL)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t le, ri;

	if (tree == NULL)
	{
		return (0);
	}	le = binary_tree_height(tree->left);
	ri = binary_tree_height(tree->right);

	if (le >= ri)
	{
		return (1 + le);
	}	return (1 + ri);
}

/**
 * binary_tree_is_perfect -> binary tree is perfect
 *@tree: It's node of the tree to check
 *Return: tree = (NULL)
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *le, *ri;

	if (tree == NULL)
	{
		return (1);
	}	le = tree->left;
	ri = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);

	if (le == NULL || ri == NULL)

		return (0);

	if (binary_tree_height(le) == binary_tree_height(ri))
	{
		if (binary_tree_is_perfect(le) && binary_tree_is_perfect(ri))
			return (1);
	}	return (0);
}
