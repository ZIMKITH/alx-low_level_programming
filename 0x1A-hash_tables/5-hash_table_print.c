#include "hash_tables.h"

/**
 * Hash_table_print - print hash maps
 * @ht: HashTable
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	hash_node_t *node;
	char *comma = "";

	if (!ht || !ht->array)
	{
		return;
	}

	printf("{");
	while (idx < ht->size)
	{
		node = ((ht->array)[idx]);
		while (node)
		{
			printf("%s'%s': '%s'", comma, node->key, node->value);
			comma = ", ";
			node = node->next;
		}
		idx++;
	}
	printf("}\n");
}
