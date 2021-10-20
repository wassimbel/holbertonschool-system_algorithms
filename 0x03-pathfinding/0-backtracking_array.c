#include "pathfinding.h"
queue_t *backtrack(int x, int y, char **map,
			point_t const *target, int cols, int rows, queue_t *path);

/**
 * backtracking_array - searches for the first path
 * @map: pointer to a read-only two-dimensional array
 * @rows: the number of rows of map
 * @cols: the number of columns of map
 * @start: stores the coordinates of the starting point
 * @target: stores the coordinates of the target point
 * Return: a queue in which each node is a point from start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
				point_t const *start, point_t const *target)
{

	queue_t *path;
	int i, x = 0, y = 0;
	static char **visited;

	path  = queue_create();
	x = start->x;
	y = start->y;
	visited = malloc(sizeof(char *) * rows);
	if (!visited)
		return (NULL);
	for (i = 0; i < rows; i++)
		visited[i] = strdup(map[i]);

	(backtrack(x, y, visited, target, cols, rows, path));
	for (i = 0; i < rows; i += 1)
		free(visited[i]);
	free(visited);
	return (path);
}

/**
 * backtrack- backtraking
 * @x: coordinate of x pos
 * @y: coordinate of y pos
 * @map: pointer to a read-only two-dimensional array
 * @target: stores the coordinates of the target point
 * @rows: number of rows
 * @cols: number of cols
 * @path: current path
 * Return: queue path
 */
queue_t *backtrack(int x, int y, char **map,
			point_t const *target, int rows, int cols, queue_t *path)
{
	point_t *point;
	(void) path;
	(void) target;
	if (x < 0 || y < 0 || x >= cols || y >= rows ||
		map[y][x] == '1' || map[y][x] == '2')
		return (NULL);
	map[y][x] = '2';

	printf("Checking coordinates [%d, %d]\n", x, y);

	if ((target->x == x && target->y == y) ||
		backtrack(x + 1, y, map, target, cols, rows, path) ||
		backtrack(x, y + 1, map, target, cols, rows, path) ||
		backtrack(x - 1, y, map, target, cols, rows, path) ||
		backtrack(x, y - 1, map, target, cols, rows, path))
	{
		point = malloc(sizeof(point_t));
		point->x = x;
		point->y = y;
		queue_push_front(path, point);

		return (path);
	}
	return (NULL);
}
