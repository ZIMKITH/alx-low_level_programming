#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returned all  numbers of elements
 * @h: Pointers of the list_t list
 *
 * Return:  Elements numbers in h
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
