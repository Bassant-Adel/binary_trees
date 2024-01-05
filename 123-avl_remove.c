#include "binary_trees.h"

/**
 * avl_remove -> removes a node from an AVL tree
 *@root: It's the tree for removing a node
 *@value: It's in the tree
 *Return: A pointer of tree after removing desired value
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
	{
		return (NULL);
	}	bal(&root_a);
	return (root_a);
}

/**
 * bal -> Write balance factor of a AVL
 *@tree: It's a pointer of the tree to check
 *Return: A pointer root node of tree
 */

void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
	{
		return;

	}	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);

	if (bval > 1)
	{
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	}

	else if (bval < -1)
	{
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
	}
}

/**
 * successor -> Write get the next successor
 *@node: It's a pointer
 *Return: The min value
 */

int successor(bst_t *node)
{
	int le = 0;

	if (node == NULL)
		return (0);
	else
	{
		le = successor(node->left);

		if (le == 0)
		{
			return (node->n);
		}	return (le);
	}
}

/**
 *remove_type -> Write a function nding of children
 *@root: It's a pointer to the tree for removing a node
 *Return: (0) -> other value if it has
 */

int remove_type(bst_t *root)
{
	int bval = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
		{
			root->parent->left = NULL;
		}	free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
			{
				root->parent->left = root->right;
			}	root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
			{
				root->parent->left = root->left;
			}	root->left->parent = root->parent;
		}	free(root);
		return (0);
	}
	else
	{
		bval = successor(root->right);
		root->n = bval;
		return (bval);
	}
}

/**
 * bst_remove -> Write a node from a BST tree
 *@root: It's a pointer the tree for removing a node
 *@value: It's the value tree
 *Return: The tree changed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int ri = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)
	{
		ri = remove_type(root);

		if (ri != 0)
			bst_remove(root->right, ri);
	}
	else
	{
		return (NULL);
	}	return (root);
}
