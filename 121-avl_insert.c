#include "binary_trees.h"

/**
 * avl_insert -> Write inserts a value in an AVL Tree
 *@tree: It's a AVL tree for inserting value
 *@value: It's in the node to be inserted
 *Return: A pointer -> failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *anew = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}	avl_value(tree, *tree, &anew, value);
	return (anew);

}

/**
 * height ->  Measures height of a binary tree
 *@tree: the root node of the tree
 *Return: (tree) = (NULL)
 */

size_t height(const binary_tree_t *tree)
{

	if (tree != NULL)
	{
		size_t le = 0, ri = 0;

		le = tree->left ? 1 + binary_tree_height(tree->left) : 1;

		ri = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((le > ri) ? le : ri);

	}	return (0);

}

/**
 * balance -> Write a function to factor of a binary tree
 *@tree: It's a node of the tree
 *Return: (tree) = (0)
 */

int balance(const binary_tree_t *tree)
{

	size_t le = 0, ri = 0;

	le = height(tree->left);

	ri = height(tree->right);

	return (tree != NULL ? le - ri : 0);

}

/**
 * avl_value -> value into AVL tree recursively
 *@tree: It's a pointer tree
 *@parent: It's a pointer
 *@new: It's a double store new node
 *@value: It's the node to be inserted
 *Return: A pointer to new root
 */

avl_t *avl_value(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int fac;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_value(&(*tree)->left, *tree, new, value);

		if ((*tree)->left == NULL)
			return (NULL);	}

	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_value(&(*tree)->right, *tree, new, value);

		if ((*tree)->right == NULL)
			return (NULL);	}
	else
	{
		return (*tree);
	}	fac = balance(*tree);

	if (fac > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);

	else if (fac < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);

	else if (fac > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);	}

	else if (fac < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}	return (*tree);
}
