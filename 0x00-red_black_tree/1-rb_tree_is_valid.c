#include "rb_trees.h"

/**
 * rb_tree_is_valid -  checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 **/

int rb_tree_is_valid(const rb_tree_t *tree)
{
	size_t black_left = 0;

	if (!tree || tree->color != BLACK)
		return (0);
	return (check_black_and_validate(tree, &black_left));
}

/**
 * check_black_and_validate - checks for black nodes number and valid
 * Red_Black tree
 * @tree: pointer to the root node of the tree to check
 * @black_left: pointer to number of left black nodes
 * Return: 1 on success otherwise 0
 **/

int check_black_and_validate(const rb_tree_t *tree, size_t *black_left)
{
	size_t black_right = 0;

	if (!tree)
		return (1);

	if (check_color(tree) == 0 || check_bst(tree) == 0)
		return (0);
	if (!check_black_and_validate(tree->left, black_left) ||
		 !check_black_and_validate(tree->right, &black_right) ||
			 *black_left != black_right)
		return (0);
	if (tree->color == BLACK)
		*black_left += 1;
	return (1);
}

/**
 * check_bst - checks if tree is binary search tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 on success otherwise 0
 **/

int check_bst(const rb_tree_t *tree)
{
	if ((tree->left && tree->left->n > tree->n) ||
		 (tree->right && tree->right->n < tree->n))
		return (0);
	return (1);
}

/**
 * check_color - checks if tree is either red or black and
 * no two adjacent red nodes.
 * @tree: pointer to the root node of the tree to check
 * Return: 1 on success otherwise 0
 **/

int check_color(const rb_tree_t *tree)
{
	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED && tree->left && tree->left->color == RED)
		return (0);
	if (tree->color == RED && tree->right && tree->right->color == RED)
		return (0);

	return (1);
}
