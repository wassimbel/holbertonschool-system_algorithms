#include "rb_trees.h"

/**
 * rb_tree_insert -  inserts a value in a Red-Black Tree
 * @tree: double pointer to the root node of the Red-Black
 * @value: value to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 */

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node;

	if (!tree)
		return (NULL);
	new_node = rb_insert(tree, value);
	if (!new_node)
		return (NULL);
	rb_inserted(tree, new_node);
	return (new_node);
}

/**
 * rb_insert -  inserts a Red-Black Tree node
 * @tree: double pointer to red black tree
 * @value: the value to put in the new node
 * Return: returns a pointer to the new node, or NULL on failure
 **/

rb_tree_t *rb_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *parent = NULL, *current, *new_node;

	current = *tree;

	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}
	new_node = rb_tree_node(NULL, value, RED);

	if (!new_node)
		return (NULL);
	new_node->parent = parent;

	if (!parent)
		*tree = new_node;
	else if (new_node->n < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}

/**
 * fix_right_uncle -  fixes the right uncle
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */

void fix_right_uncle(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->right && node->parent->parent->right->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->right->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			left_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		right_rotate(tree, node->parent->parent);
	}
}

/**
 * fix_left_uncle -  fixes the left uncle
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */

void fix_left_uncle(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->left && node->parent->parent->left->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->left->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			right_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		left_rotate(tree, node->parent->parent);
	}
}

/**
 * left_rotate -  rotates subtree to left
 * @tree: double pointer to root node
 * @node: pointer to node to rotate
 */

void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *right_child;

	right_child = node->right;

	node->right = right_child->left;

	if (!right_child)
		return;

	if (right_child->left)
		right_child->left->parent = node;

	right_child->parent = node->parent;

	if (node->parent == NULL)
		*tree = right_child;
	else if (node == node->parent->left)
		node->parent->left = right_child;
	else
		node->parent->right = right_child;

	right_child->left = node;
	node->parent = right_child;
}

/**
 * right_rotate -  rotates subtree to right
 * @tree: double pointer to root node
 * @node: pointer to node to rotate
 */

void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *left_child;

	left_child = node->left;

	node->left = left_child->right;

	if (!left_child)
		return;
	if (left_child->right)
		left_child->right->parent = node;

	left_child->parent = node->parent;

	if (node->parent == NULL)
		*tree = left_child;
	else if (node == node->parent->right)
		node->parent->right = left_child;
	else
		node->parent->left = left_child;

	left_child->right = node;
	node->parent = left_child;
}

/**
 * rb_inserted - rotate and recolor inserted nodes
 * @tree: double pointer to root node
 * @node: node to fix
 **/

void rb_inserted(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent && node->parent == node->parent->parent->left)
			fix_right_uncle(tree, node);
		else
			fix_left_uncle(tree, node);

	}
	(*tree)->color = BLACK;
}
