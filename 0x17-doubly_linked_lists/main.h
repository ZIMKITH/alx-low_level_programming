#ifndef _MAIN_H_
#define _MAIN_H_

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Struct */

/**
 * Struct dlistint_s - Have to manage doubly linked list
 * @n: Integers
 * @Prev: The previous node with points.
 * @Next: The next node
 *
 * Description: Doubly linked list structures
 *
 */
typedef struct dlistint_s
{
        int n;
        struct dlistint_s *prev;
        struct dlistint_s *next;
} dlistint_t;

/* Prototypes */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);

#endif /* end of LISTS_H file */
