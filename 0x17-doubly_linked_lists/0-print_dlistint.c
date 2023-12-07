#include "main.h"

/**
 * print_dlistint - Prints all elements of a dlistint_t list
 * @h: Pointer to the head of the doubly linked list
 * Return: Number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t num_nodes = 0;

    if (h == NULL)
    {
        return num_nodes;
    }

    while (h->prev != NULL)
    {
        h = h->prev;
    }

    while (h != NULL)
    {
        printf("%d\n", h->n);
        num_nodes++;
        h = h->next;
    }

    return num_nodes;
}
