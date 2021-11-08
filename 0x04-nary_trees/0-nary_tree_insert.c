#include "nary_trees.h"

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->content = strdup(str);
	if (!new_node->content)
	{
		free(new_node->content);
		return (NULL);
	}
	new_node->parent = parent;
	new_node->nb_children = 0;
	new_node->children = NULL;
	if (parent)
	{
	++parent->nb_children;
	new_node->next = parent->children;
	parent->children = new_node;
	}
	else
		new_node->next = NULL;
	return (new_node);
}
