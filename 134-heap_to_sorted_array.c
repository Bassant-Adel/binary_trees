#include "binary_trees.h"

/**
 * heap_to_sorted_array -> Wrts a Binary
 *@heap: It's a pointer to the rert
 *@size: It's an address
 *Return: An array must
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int ex, b = 0;
	size_t heaps;

	if (!heap)
		return (NULL);

	heaps = binary_tre_size(heap);

	*size = heaps;

	arr = malloc(heaps * sizeof(int));

	if (!arr)
		return (NULL);

	while (heap)
	{
		ex = heap_extract(&heap);
		arr[b] = ex;
		b++;

	}	return (arr);
}
