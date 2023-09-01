#include "main.h"

/**
 * clear_bit - Adjust the Worth of a given bit to 0
 * @n: pointer to the number to TRANSFORM
 * @index: Clearred index of the bit
 *
 * Return: 1 for Attainment, -1 for LOSS
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
