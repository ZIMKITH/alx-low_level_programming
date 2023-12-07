#include "lists.h"

/**
 * add_dnodeint_end - New node added at dlistint_t list end
 * @head: Head pointers
 * @n: Element value
 * Return: Element address
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new_elem;

	new_elem = malloc(sizeof(dlistint_t));
	if (new_elem == NULL)
	{
		return (NULL);
	}

	new_elem->n = n;
	new_elem->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
		{
			h = h->next;
		}
		h->next = new_elem;
	}
	else
	{
		*head = new_elem;
	}

	new_elem->prev = h;

	return (new_elem);
}
