#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return:  a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	newroot = tree->right;
	tree->right = newroot->left;

	if (newroot->left != NULL)
	{
		newroot->left->parent = tree;
	}
	newroot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = newroot;
		else
			tree->parent->right = newroot;
	}
	newroot->left = tree;
	tree->parent = newroot;

	return (newroot);
}
