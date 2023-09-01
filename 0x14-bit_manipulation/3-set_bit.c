#include "main.h"

/**
 * set_bit - Sets a bit at a PROVIDED index to 1
 * @n: Changed POINTER
 * @index: index of the bit to REGULATE to 1
 *
 * Return: 1 successful, -1 for CUT out
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
