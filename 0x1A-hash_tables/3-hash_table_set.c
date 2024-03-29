#include "hash_tables.h"

/**
 * create_and_add_node - insert NODE, into hash table
 * @ht: Hash table
 * @key: key to unlock strings
 * @value: Value
 * @idx: index with hash table
 * Return: success = 1, 0 on fail
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
		unsigned long int idx)
{
	hash_node_t *node = NULL;
	char *k;
	char *v;

	node = malloc(sizeof(hash_node_t));
	if (!node)
	{
		return (0);
	}

	k = strdup(key);
	if (!k)
	{
		free(node);
		return (0);
	}

	v = strdup(value);
	if (!v)
	{
		free(k);
		free(node);
		return (0);
	}

	node->key = k;
	node->value = v;

	if ((ht->array)[idx] == NULL)
		node->next = NULL;
	else
		node->next = (ht->array)[idx];
	(ht->array)[idx] = node;

	return (1);
}


/**
 * hash_table_set - hash map
 * @ht: hash tables sett
 * @key: key to unlock the strings
 * @value: values
 * Return: success = 1, 0 on fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* get index */
	/* if key already exists, update value and return */
	/* else create node */
	/* set ht idx ptr to node; else add node to front if collision */

	unsigned long int idx;
	hash_node_t *node = NULL;
	char *v;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
	{
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		v = strdup(value);
		if (!v)
		{
			return (0);
		}
		if (node->value)
			free(node->value);
		node->value = v;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}
