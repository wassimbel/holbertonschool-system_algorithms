#include "graphs.h"

/**
 * dfs - recursive function using depth first traversal
 * @vertex: pointer to vertex
 * @action: pointer to a function to be called for each visited vertex
 * @depth: current depth
 * @max_depth: maximum depth found
 * @seen: array of ints representing seen vertices
 **/

void dfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
			 size_t depth, size_t *max_depth, int *seen)
{
	edge_t *current;

	if (!vertex || seen[vertex->index])
		return;
	action(vertex, depth);
	seen[vertex->index] = 1;
	if (depth > *max_depth)
		*max_depth = depth;
	depth++;

	current = vertex->edges;

	while (current)
	{
		dfs(current->dest, action, depth, max_depth, seen);
		current = current->next;
	}
}

/**
 * depth_first_traverse - goes through a graph using the depth-first algorithm.
 * @graph: pointer to graph to traverse
 * @action: pointer to a function to be called for each visited vertex
 * Return:the biggest vertex depth or 0 on failure
 **/

size_t depth_first_traverse(const graph_t *graph,
				void (*action)(const vertex_t *v, size_t depth))
{

	size_t max_depth = 0;
	int *seen;

	if (!graph || !action)
		return (0);

	seen = calloc(graph->nb_vertices, sizeof(*seen));

	if (!seen)
		return (0);

	dfs(graph->vertices, action, 0, &max_depth, seen);
	free(seen);
	return (max_depth);
}
