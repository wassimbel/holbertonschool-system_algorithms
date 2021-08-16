#include "graphs.h"

/**
 * graph_delete - completely deletes a graph
 * @graph: pointer to graph
 **/

void graph_delete(graph_t *graph)
{
	vertex_t *current, *next = NULL;
	edge_t *edge = NULL, *cur_edge = NULL;
	if (!graph)
		return;

	current = graph->vertices;

	while (current)
	{
		edge = current->edges;

		while (edge)
		{
			cur_edge = edge;
			edge = edge->next;
			free(cur_edge);
		}
		next = current;
		current = current->next;
		free(next->content);
		free(next);
	}
	free(graph);
}
