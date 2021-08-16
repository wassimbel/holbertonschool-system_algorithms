#include "graphs.h"

/**
 * check_edge - checks if edge between v_src and v_dest exists
 * @v_src: pointer to src vertex
 * @v_dest: pointer to dest vertex
 * Return: returns 1 if edge exists otherwise 0
 **/

int check_edge(vertex_t *v_src, vertex_t *v_dest)
{
	edge_t *current = NULL;

	if (!v_src || v_dest)
		return (0);

	current = v_src->edges;

	while (current)
	{
		if (current->dest == v_dest)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * vertex_pt - returns a pointer to vertex containing s
 * @graph: pointer to graph
 * @s: pointer to string
 * Return: returns a pointer to found vertex or NULL on failure
 **/

vertex_t *vertex_pt(graph_t *graph, const char *s)
{
	vertex_t *current;

	if (!graph || !s)
		return (NULL);

	current = graph->vertices;

	while (current)
	{
		if (strcmp(current->content, s) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/**
 * add_edge - add an edge between 2 vertices
 * @v_src: pointer to src vertex
 * @v_dest: pointer to dest vertex
 * Return: returns 1 on success otherwise 0
 **/

int add_edge(vertex_t *v_src, vertex_t *v_dest)
{
	edge_t *current, *new_edge;

	if (!v_src || !v_dest)
		return (0);

	current = v_src->edges;

	new_edge = NULL;

	while (current && current->next)
		current = current->next;
	new_edge = malloc(sizeof(*new_edge));

	if (!new_edge)
		return (0);

	new_edge->dest = v_dest;
	new_edge->next = NULL;
	if (!v_src->edges)
	{
		v_src->edges = new_edge;
		v_src->nb_edges += 1;
		return (1);
	}
	else
	{
		current->next = new_edge;
		v_src->nb_edges += 1;
		return (1);
	}
	return (0);
}

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 * @graph: pointer to the graph to add the edge to
 * @src: string identifying the vertex to make the connection from
 * @dest: string identifying the vertex to connect to
 * @type: type of edge
 * Return: returns 1 on success otheriwse 0
 */

int graph_add_edge(graph_t *graph, const char *src, const char *dest,
			 edge_type_t type)
{
	vertex_t *v_src, *v_dest;

	if (!graph || !src || !dest ||
		 (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);

	v_src = vertex_pt(graph, src);
	v_dest = vertex_pt(graph, dest);
	if (type == BIDIRECTIONAL)
	{
		if (check_edge(v_src, v_dest) && check_edge(v_dest, v_src))
			return (1);
		if (!add_edge(v_src, v_dest))
			return (0);
		if (!add_edge(v_dest, v_src))
			return (0);
	}
	else
	{
		if (check_edge(v_src, v_dest))
			return (1);
		if (!add_edge(v_src, v_dest))
			return (0);
	}
	return (1);
}
