#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = malloc(sizeof(binary_tree_t));

	/*checks if memory allocation fails */
	if (newnode == NULL)
	{
		return (NULL);
	}
	else
	{
		newnode->n = value;
		newnode->parent = parent;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	return (newnode);
}
