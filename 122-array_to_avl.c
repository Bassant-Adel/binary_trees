#include "binary_trees.h"

/**
 * array_to_avl -> Write auilds an AVL tree from an array
 *@array: It's a pointer to be converted
 *@size: It's the ment in the array
 *Return: A pointer to root node of created AVL tree || (NULL)-> failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;

		}

		if (b == a)
		{

			if (avl_insert(&tree, array[a]) == NULL)
				return (NULL);
		}

	}	return (tree);

}
