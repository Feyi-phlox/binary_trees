#include "binary_trees.h"

/**
 * binary_tree_height- function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * If tree is NULL, your function must return 0
 * Return: height of a binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}
/**
 * do_levelorder - Helper function to traverse level of the binary tree
 * @node: Pointer to the current node
 * @func: Pointer to a function to call for each node's value
 * @level: Current level being traversed
 */

void do_levelorder(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
	{
		func(tree->n);
	}
	else
	{
		do_levelorder(tree->left, level - 1, func);
		do_levelorder(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder -Goes through binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int lvl;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	for (lvl = 0; lvl < height; lvl++)
		do_levelorder(tree, lvl, func);
}
