#include "limits.h"
#include "binary_trees.h"

/**
 * binary_tree_is_bst -> that checks if a binary
 *@tree: It's a pointer
 *Return: tree is valid BST -> (1) & (NULL) -> (0)
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}	return (binary_bst(tree, INT_MIN, INT_MAX));

}

/**
 * binary_bst -> checks if a binary
 *@tree: It's node of the tree to check
 *@sm: It's sm
 *@la: It's la
 *Return: tree is a valid BST -> (1)
 */

int binary_bst(const binary_tree_t *tree, int sm, int la)
{

	if (tree != NULL)
	{
		if (tree->n < sm || tree->n > la)
		{
			return (0);
		}	return (binary_bst(tree->left, sm, tree->n - 1) &&
				binary_bst(tree->right, tree->n + 1, la));
	}	return (1);
}
