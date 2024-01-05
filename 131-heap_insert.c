#include "binary_trees.h"

/**
 * heap_insert -> Write a f in Max Binary Heap
 *@root: It's a doubl to insert value
 *@value: It's inserted
 *Return: A pointer
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *he = NULL, *ro;

	if (!root)
	{
		return (NULL);
	}	he = calloc(1, sizeof(heap_t));
	he->n = value;

	if (!*root)
	{
		*root = he;
		return (he);
	}	insert(root, he);

	while (he->parent && he->n > he->parent->n)
	{
		ro = swap(he->parent, he);

		if (ro)
			*root = ro;
	}	return (he);

}

/**
 * swap -> Write nodes in binary tree
 *@f: It's a 1 node
 *@s: It's a 2 node
 *Return: A pointer
 */

bst_t *swap(bst_t *f, bst_t *s)
{
	bst_t a_c = INIT_NODE;

	a_c.n = f->n;
	a_c.parent = f->parent;
	a_c.left = f->left;
	a_c.right = f->right;
	f->parent = s;
	f->left = s->left;
	f->right = s->right;
	if (s->left)
		s->left->parent = f;
	if (s->right)
	{
		s->right->parent = f;  }
	s->parent = a_c.parent;

	if (a_c.parent)
	{
		if (f == a_c.parent->left)
			a_c.parent->left = s;
		else
			a_c.parent->right = s;
	}
	if (s == a_c.left)
	{
		s->left = f;
		s->right = a_c.right;
		if (a_c.right)
			a_c.right->parent = s;
	}
	else if (s == a_c.right)
	{
		s->right = f;
		s->left = a_c.left;
		if (a_c.left)
			a_c.left->parent = s;	}
	while (s->parent)
		s = s->parent;
	return (s);
}

/**
 * convert -> Write a function thing
 *@num: It's a num
 *@base: It's a base
 *@lowercase: It's a lowercase
 *Return: A str
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	static char *low;
	static char buffer[50];
	char *item;

	low = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	item = &buffer[49];
	*item = 0;

	do {
		*--item = low[num % base];
		num /= base;
	} while (num);

	return (item);
}

/**
 * binary_tree_size -> Write a function that
 *@tree: It's a binary
 *Return: An number
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert -> Write a function to help
 *@root: It's a double pointer
 *@node: It's a node
 *Return: Void no
 */

void insert(heap_t **root, heap_t *node)
{
	heap_t *item;
	int asize;
	unsigned int a;
	char *binary;
	char b;

	item = *root;
	asize = binary_tree_size(item) + 1;
	binary = convert(asize, 2, 1);

	for (a = 1; a < strlen(binary); a++)
	{
		b = binary[a];
		if (a == strlen(binary) - 1)
		{
			if (b == '1')
			{
				node->parent = item;
				item->right = node;
				break;
			}
			else if (b == '0')
			{
				node->parent = item;
				item->left = node;
				break;			}
		}
		if (b == '1')
			item = item->right;
		else if (b == '0')
			item = item->left;
	}
}
