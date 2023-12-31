#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * If tree is NULL, the function must return 0
 * Return: the size of a binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
	{
		return (0);
	}

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
