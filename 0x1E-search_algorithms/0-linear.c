#include "search_algos.h"
#include <stddef.h>
#include <stdio.h>

/**
 * linear_search - Function serch for a value in it
 * @array: array of ints
 * @size: size of array
 * @value: value to search for
 * Return: position or -1 if not a value
 *
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1); /* Return -1 if the array is NULL */

	for (i = 0; i < size; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i); /* Return the index if the value is found */
	}
	return (-1); /* Return -1 if the value is not found in the array */
}
