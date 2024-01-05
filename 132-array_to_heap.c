#include "binary_trees.h"

/**
 * array_to_heap -> Write a array
 *@array: It be converted
 *@size: It's array
 *Return: A pointer to root node
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t b = 0;
	bst_t *ronde = NULL;

	if (!array)
		return (NULL);

	while (b < size)
	{
		heap_insert(&ronde, array[b]);
		b++;
	}	return (ronde);
}
