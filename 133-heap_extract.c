#include "binary_trees.h"
#define INIT_NODE {0, NULL, NULL, NULL}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CONVERT "0123456789ABCDEF"
#define SETUP_NODE_BLOC { \
	tmp = *root; \
	size = binary_tre_size(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}
#define FREE_NODE_BLOC { \
		res = tmp->n; \
		free(tmp); \
		*root = NULL; \
	}
#define SWAP_HEAD_BLOC { \
		head = *root; \
		head = swap_head(head, tmp); \
		res = head->n; \
		free(head); \
		*root = tmp; \
		tmp = percy_down(tmp); \
		*root = tmp; \
	}
#define CONVERT_LOOP { \
		*--binary = CONVERT[size % 2]; \
		size /= 2; \
	}

/**
 * heap_extract -> Write a func Max Binary Heap
 *@root: It's a double root node of heap
 *Return: the root node, if fails -> (0)
 */

int heap_extract(heap_t **root)
{
	size_t size, i;
	char *binary, c, buffer[50];
	int res;
	heap_t *tmp, *head;

	if (!root || !*root)
	{
		return (0);
	}	SETUP_NODE_BLOC;
	if (size == 1)
	{
		FREE_NODE_BLOC;
		return (res);	}
	do {
		CONVERT_LOOP;
	} while (size);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				tmp = tmp->right;
				break;
			}
			else if (c == '0')
			{
				tmp = tmp->left;
				break;			}
		}
		if (c == '1')
			tmp = tmp->right;
		else if (c == '0')
			tmp = tmp->left;
	}	SWAP_HEAD_BLOC;
	return (res);
}

/**
 * nswap -> Write a function to swap 2 tree
 *@f: It's f
 *@s: It's s
 *Return: A pointer
 */

bst_t *nswap(bst_t *f, bst_t *s)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = f->n;
	a_copy.parent = f->parent;
	a_copy.left = f->left;
	a_copy.right = f->right;
	f->parent = s;
	f->left = s->left;
	f->right = s->right;
	if (s->left)
		s->left->parent = f;
	if (s->right)
		s->right->parent = f;
	s->parent = a_copy.parent;
	if (a_copy.parent)
	{
		if (f == a_copy.parent->left)
			a_copy.parent->left = s;
		else
			a_copy.parent->right = s;	}
	if (s == a_copy.left)
	{
		s->left = f;
		s->right = a_copy.right;
		if (a_copy.right)
			a_copy.right->parent = s;
	}
	else if (s == a_copy.right)
	{
		s->right = f;
		s->left = a_copy.left;
		if (a_copy.left)
			a_copy.left->parent = s;
	}
	while (s->parent)
		s = s->parent;
	return (s);
}

/**
 * binary_tre_size -> Write of a binary tree
 *@tree: It's a binary
 *Return: An number
 */

size_t binary_tre_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}	return (1 + binary_tre_size(tree->left) + binary_tre_size(tree->right));
}

/**
 * swap_head -> Write a function to help
 *@head: It's a pointer
 *@node: It's a pointer
 *Return: A pointer
 */

heap_t *swap_head(heap_t *head, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	} else
	{
		node->parent->right = NULL;

	}	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;

	if (head->left)
		head->left->parent = node;

	if (head->right)
	{
		head->right->parent = node;

	}	return (head);
}

/**
 * percy_down -> Write a function to pertion
 *@node: It's a pointer
 *Return: A pointer
 */

heap_t *percy_down(heap_t *node)
{
	int max;
	heap_t *next = node;

	if (!node)
		return (NULL);
	max = node->n;

	if (node->left)
		max = MAX(node->left->n, max);

	if (node->right)
		max = MAX(node->right->n, max);

	if (node->left && max == node->left->n)
		next = node->left;

	else if (node->right && max == node->right->n)
		next = node->right;

	if (next != node)
	{
		nswap(node, next);

		percy_down(node);

	}	return (next);
}
