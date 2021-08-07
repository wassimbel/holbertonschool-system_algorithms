#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph:  pointer to the graph to add the vertex to
 * @str: the string to store in the new vertex
 * Return: return a pointer to the created vertex, or NULL on failure
 **/

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *current, *prev;

	if (!graph || !str)
		return (NULL);

	current = graph->vertices;

	while (current)
	{
		if (strcmp(current->content, str) == 0)
			return (NULL);
		prev = current;
		current = current->next;
	}

	new_vertex = malloc(sizeof(*new_vertex));

	if (!new_vertex)
		return (NULL);

	new_vertex->content = strdup(str);
	new_vertex->index = 0;
	new_vertex->edges = NULL;
	new_vertex->nb_edges = 0;
	new_vertex->next = NULL;

	if (!prev)
	{
		new_vertex->index = 0;
		graph->vertices = new_vertex;
	}
	else
	{
		new_vertex->index = prev->index + 1;
		prev->next = new_vertex;
	}
	graph->nb_vertices += 1;
	return (new_vertex);
}
