#include "rb_trees.h"

/**
 * rb_tree_node -  creates a Red-Black Tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * @color: the color of the node
 * Return: returns a pointer to the new node, or NULL on failure
 **/

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_tree;

	if (color != RED && color != BLACK && color != DOUBLE_BLACK)
		return (NULL);

	new_tree = malloc(sizeof(*new_tree));

	if (!new_tree)
		return (NULL);
	new_tree->parent = parent;
	new_tree->n = value;
	new_tree->color = color;
	new_tree->left = NULL;
	new_tree->right = NULL;
	return (new_tree);
}
