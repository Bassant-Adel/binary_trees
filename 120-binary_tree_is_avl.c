#include "limits.h"
#include "binary_trees.h"

/**
 * binary_tree_is_avl -> Write a function
 *@tree: It's the root node of the tree to check
 *Return: (0)-> otherwise, (tree) = (NULL)-> (0)
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);

	}	return (is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * height ->  Measures height of a binary tree
 *@tree: the root node of the tree
 *Return: (NULL)-> (0), (height)
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;

		r = tree->right ? 1 + height(tree->right) : 1;

		return ((l > r) ? l : r);

	}	return (0);

}

/**
 * is_avl -> if a binary tree is valid AVL tree
 *@tree: root node
 *@sm: It's smallest node
 *@la: It's largest node
 *Return: (tree)
 */

int is_avl(const binary_tree_t *tree, int sm, int la)
{
	size_t leh, rih, item;

	if (tree != NULL)
	{
		if (tree->n < sm || tree->n > la)
		{
			return (0);
		}	leh = height(tree->left);

		rih = height(tree->right);

		item = leh > rih ? leh - rih : rih - leh;

		if (item > 1)
		{
			return (0);

		}	return (is_avl(tree->left, sm, tree->n - 1) &&
				is_avl(tree->right, tree->n + 1, la));
	}	return (1);
}
