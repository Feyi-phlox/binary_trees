#include "binary_trees.h"

/**
 * max_value - Finds the maximum value in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Maximum value in the tree
 */

int max_value(const binary_tree_t *tree)
{
	int leftmax, rightmax;

	if (tree == NULL)
	{
		return (0);
	}

	leftmax = max_value(tree->left);
	rightmax = max_value(tree->right);

	return ((tree->n > leftmax && tree->n > rightmax) ? tree->n :
			(leftmax > rightmax) ? leftmax : rightmax);
}

/**
 * min_value - Finds the minimum value in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Minimum value in the tree
 */

int min_value(const binary_tree_t *tree)
{
	int leftmin, rightmin;

	if (tree == NULL)
	{
		return (INT_MAX);
	}

	leftmin = min_value(tree->left);
	rightmin = min_value(tree->right);

	return ((tree->n < leftmin && tree->n < rightmin) ? tree->n :
			(leftmin < rightmin) ? leftmin : rightmin);
}

/**
 * check_isbst - Checks if a binary tree is a valid BST recursively
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */

int check_isbst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min_value(tree->left) && tree->left)
		return (0);
	if (tree->n >= max_value(tree->right && tree->right)
		return (0);

	return (check_isbst(tree->left) && check_isbst(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (check_isbst(tree));
}
