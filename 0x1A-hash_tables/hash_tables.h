#ifndef _HASH_TABLES_
#define _HASH_TABLES_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct hash_node_s - Node with hash table
 *
 * @key: strings key
 * unique key in the Hashmap
 * @value: the value c
 * @next: pointers of the next node
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - \Data structures
 *
 * @size: The size of an array
 * @array: Array with sizes
 * The pointer of the first NODE
 * because we want our Hashmap.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* function prototypes */
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);


/* structures and function prototypes for 100-sorted_hash_table.c */
/**
 * Struct shash_node_s - Node sorted with hash table
 *
 * @key: String with keys
 * The key is unique in the Hashmap
 * @value: The value with a key
 * @next: A next node on the list withn pointers
 * @sprev: sorted linked previous element
 * @snext: sorted  next element
 */
typedef struct shash_node_s
{
        char *key;
        char *value;
        struct shash_node_s *next;
        struct shash_node_s *sprev;
        struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sort hash tables with data structures
 *
 * @size: The rray
 * @array: An array with a size
 * @shead: A pointer of the first element
 * @stail: A pointer of the last element
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

#endif /* end of HASH_TABLES file */
