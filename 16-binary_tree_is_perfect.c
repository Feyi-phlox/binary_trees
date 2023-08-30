#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	if (tree == NULL)
	{
		return (-1);
	}

	left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t size = 2;

	if (tree == NULL)
	{
		return (0);
	}

	height = binary_tree_height(tree);
	while (height--)
	{
		size *= 2;
	}

	return (size - 1 == binary_tree_size(tree));
}
