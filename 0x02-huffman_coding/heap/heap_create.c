#include "heap.h"

/**
 * heap_create - creates a heap data structure
 * @data_cmp: a pointer to a comparison function
 * Return: a pointer to the created heap_t structure, or NULL if it fails
 **/

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap;

	new_heap = malloc(sizeof(*new_heap));

	if (!new_heap)
		return (NULL);

	new_heap->root = NULL;
	new_heap->data_cmp = data_cmp;
	new_heap->size = 0;

	return (new_heap);
}
