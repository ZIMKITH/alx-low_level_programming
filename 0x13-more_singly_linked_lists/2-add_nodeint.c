#include "lists.h"

/**
 * add_nodeint - Add nodes at the beginning of a  list
 * @head: Pointer of the first node in the list
 * @n: Data inserted in a new node
 *
 * Return: pointers of the new node.  if it fails = NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
