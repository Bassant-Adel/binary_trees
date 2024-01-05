#include "binary_trees.h"

/**
 * sorted_array_to_avl -> AVL tree from array
 *@array: It's the array to be converted
 *@size: It's the number
 *Return: AVL tree || (NULL)-> failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (sorted_avl(array, 0, size - 1, NULL));
}

/**
 * sorted_avl -> Write a function
 *@array: It's a pointer be converted
 *@start: The sta
 *@end: The en
 *@parent: It's node
 *Return: The nnode
 */

avl_t *sorted_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *nar;
	int ar;

	if (start > end)
		return (NULL);
	ar = (start + end) / 2;
	nar = calloc(1, sizeof(avl_t));

	if (!nar)
		return (NULL);
	nar->n = array[ar];

	nar->parent = parent;

	nar->left = sorted_avl(array, start, ar - 1, nar);

	nar->right = sorted_avl(array, ar + 1, end, nar);

	return (nar);
}
