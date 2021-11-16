#include "nary_trees.h"

/**
 * nary_tree_traverse -  goes through a N-ary tree node by node.
 * @root: pointer to the root node of the tree
 * @action: a pointer to a function to execute for each travesed node
 * Return: returns the biggest depth of the tree or 0 on failure
 **/

size_t nary_tree_traverse(nary_tree_t const *root,
			void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t ret;
	static size_t depth, max_depth;

	while (root)
	{
		action(root, depth);
		++depth;
		nary_tree_traverse(root->children, action);
		root = root->next;
	}
	if (max_depth < depth)
		max_depth = depth;
	if (depth == 0)
	{
		ret = max_depth;
		max_depth = 0;
	}
	else
		--depth;
	return (ret);
}
