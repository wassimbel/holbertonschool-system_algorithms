#include "heap.h"

/**
 *
 *
 *
 **/





/**
 * binary_tree_height - measures the height of a binary
 * tree and get index of the heighest node
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of a tree or 0
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0, j = 0;
	binary_tree_t *left_position, *right_position;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	i = binary_tree_height(tree->left) + 1;
	left_position = tree->left;
	j = binary_tree_height(tree->right) + 1;
	right_postion = tree->right;

	if (i > j)
		return (left_position);
	else
		return (right_position);
}
