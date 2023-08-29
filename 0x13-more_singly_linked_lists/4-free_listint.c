#include "lists.h"

/**
 * free_Listint - linked list freed
 * @head: Listint_T list has been freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
