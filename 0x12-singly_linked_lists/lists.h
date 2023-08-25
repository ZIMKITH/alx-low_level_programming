#ifndef LISTS_H
#define LISTS_H

/**
 * struct list_s - Linked list
 * @str: String - (malloc  string)
 * @len: Length of strings
 * @next: Points for the next node
 *
 * Description: Linked list node structure
 * For Holberton Project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);

#endif

