#include "pathfinding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * backtracking_graph -  searches for the shortest path from a starting point
 *  to a target point in a graph.
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: return a queue, in which each node is a char * corresponding
 * to a vertex, forming a path from start to target
 **/
queue_t *backtracking_graph(graph_t *graph,
				vertex_t const *start, vertex_t const *target)
{
	char *visited;
	queue_t *path = queue_create();

	visited = calloc(graph->nb_vertices, sizeof(char));
	path = backtrack(path, start, target, visited);
	queue_push_front(path, strdup(start->content));
	free(visited);
	return (path);

}

/**
 * backtrack -  searches for the shortest path from a starting point
 *  to a target point in a graph.
 * @path: pointer to path
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * @visited: pointer to visited
 * Return: return a queue, in which each node is a char * corresponding
 * to a vertex, forming a path from start to target
 **/

queue_t *backtrack(queue_t *path, vertex_t const *start,
			const vertex_t *target, char *visited)
{
	edge_t *edges;
	(void) path;
	(void) start;
	(void) target;

	if (!start || visited[start->index])
		return (NULL);

	visited[start->index] = 1;
	printf("Checking %s\n", start->content);

	if (start == target)
	{
		return (path);
	}
	for (edges = start->edges; edges; edges = edges->next)
	{
		if (backtrack(path, edges->dest, target, visited))
		{
			queue_push_front(path, strdup(edges->dest->content));
			return (path);
		}
	}
	return (NULL);
}
