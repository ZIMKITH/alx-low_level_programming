#include "lists.h"

/**
 * sum_listint - Data in the listint_t list RESULTS
 * @head: First NODE linked list
 *
 * Return: Sum RESULTS
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
