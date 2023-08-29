#include "lists.h"

/**
 * pop_listint - Deleted the  head node of the linked list
 * @head: Linked list  Pointers of the first element
 *
 * Return: The data inside  elements hs been deleted.
 * If the list is empty then thats  = 0
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
