#include "hash_tables.h"

/**
 * Hash_table_create - HUash tables with given sizes
 * @Size: SIZE
 * Return: pointer To A tables, 0 on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	hash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
	{
		return (NULL);
	}
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}

	ht->size = size;
	ht->array = array;

	return (ht);
}
