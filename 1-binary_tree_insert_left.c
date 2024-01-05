#include "binary_trees.h"

/**
 * binary_tree_insert_left -> Write a functioe
 *@parent: It's a poichild in
 *@value: It's the val
 *Return: A pointer to the c parent
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode;

	if (parent == NULL)
		return (NULL);

	nnode = binary_tree_node(parent, value);

	if (nnode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		nnode->left = parent->left;
		parent->left->parent = nnode;

	}	parent->left = nnode;
	return (nnode);
}
