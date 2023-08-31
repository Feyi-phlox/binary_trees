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

/**
 * do_iscomplete - Helper function to recursively check completeness
 * @node: Pointer to the current node
 * @index: Index of the current node
 * @size: Total size of the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */

int do_iscomplete(const binary_tree_t *node, size_t index, size_t size)
{
	if (node == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (do_iscomplete(node->left, 2 * index + 1, size) &&
			do_iscomplete(node->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 * If tree is NULL, your function must return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (do_iscomplete(tree, 0, binary_tree_size(tree)));
}
