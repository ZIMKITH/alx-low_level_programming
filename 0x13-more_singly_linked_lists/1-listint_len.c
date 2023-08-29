#include "lists.h"

/**
 * listint_len - Returns  numbers  of elements in singly linked lists
 * @h: The linked list of type listint_t traverse
 *
 * Return: Listed numbers of more nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
