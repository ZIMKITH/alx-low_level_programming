#include "lists.h"

/**
 * free_listint2 - Frees all linked list
 * @head: Pointers to the listint_T list has to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
