#include "lists.h"

/**
 * get_nodeint_at_index - Certain index in a linked list Returned
 * @head: First NODE of the linked list
 * @index: Returns index of the NODE
 *
 * Return: Pointers of the node we're looking for. EQUALS TO NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
