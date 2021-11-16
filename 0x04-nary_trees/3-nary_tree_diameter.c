#include "nary_trees.h"

/**
* depth - returns max depth of a tree
* @root: pointer to root node
* @diameter: pointer to max dimaeter
* Return: returns max depth of a tree
*/
size_t depth(nary_tree_t const *root, size_t *diameter)
{
	size_t i = 0, j = 0, ret;
	nary_tree_t *child;

	if (!root)
		return (0);
	for (child = root->children; child; child = child->next)
	{
		ret = depth(child, diameter);
		if (i < ret)
		{
			j =  i;
			i = ret;
		}
		else if (j < ret)
			j = ret;
	}
	if (*diameter > i + j)
		*diameter = *diameter;
	else
	*diameter = i + j;
	return (1 + i);
}

/**
* nary_tree_diameter - computes the diameter of an N-ary tree
* @root: pointer to the root node of a tree
* Return: diameter of a tree
*/
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	depth(root, &diameter);
	return (diameter + 1);
}
