#include "lists.h"

/**
 * print_listint - Printed all elements of more Singly li nked lists
 * @h: More singly linked list of listint_t to be  printed
 *
 * Return:The number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
