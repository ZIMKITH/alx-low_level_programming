#include "lists.h"

/**
 * sum_dlistint - Return sum of all doubly linked to the function
 * list data (n)
 * @head: Head pointer
 * Return: Data sum (Success) or if empty NULL
 */
int sum_dlistint(dlistint_t *head)
{
	int data_sum;

	data_sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
		{
			head = head->prev;
		}

		while (head != NULL)
		{
			data_sum += head->n;
			head = head->next;
		}
	}

	return (data_sum);
}
