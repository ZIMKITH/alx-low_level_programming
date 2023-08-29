#include "lists.h"

/**
 * insert_nodeint_at_index - Inserted a new node into the linked list.
 * GiVEN POSITIONS
 * @head: Pointers of the first NODE in the list
 * @idx: INDEX where the new node is added
 * @n: DATA inserted in the new node
 *
 * Return: Pointer of the new NODE. if it fails = NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
