#include "main.h"


/**
 * Clear_Bit - Value of a BIT has Been SET to 0.
 * @n: Ponters of A Number Has been Changed
 * @Index: Clear INdex.
 * Return: succeSS Always 1, IF else -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
