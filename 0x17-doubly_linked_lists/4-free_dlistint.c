#include "lists.h"

/**
 * free_dlistint - Frees dlistint_t list and functions
 * @head: List head pointers
 * Return: Void head pointers
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *head_ptr;

	if (head != NULL)
	{
		while (head->prev != NULL)
		{
			head = head->prev;
		}
	}

	while ((head_ptr = head) != NULL)
	{
		head = head->next;
		free(head_ptr);
	}
}
