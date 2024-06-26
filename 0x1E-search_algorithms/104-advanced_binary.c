#include "search_algos.h"

/**
 * rec_search - Function  searches for an array int
 * value using Binary search algorithm
 *
 * @array: int array
 * @size: Array size
 * @value: Search value
 *
 * Return: Index of number
 */
int rec_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
	{
		if (half > 0)
		{
			return (rec_search(array, half + 1, value));
		}
		return ((int)half);
	}

	if (value < array[half])
	{
		return (rec_search(array, half + 1, value));
	}

	half++;
	return (rec_search(array + half, size - half, value) + half);
}

/**
 * advanced_binary - search to return
 * index of number
 *
 * @array: int array
 * @size: Array size
 * @value: Search value
 *
 * Return: Index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
	{
		return (-1);
	}

	return (index);
}
