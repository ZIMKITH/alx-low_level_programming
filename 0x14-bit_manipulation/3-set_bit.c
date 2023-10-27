#include "main.h"


/**
 * Set_Bit - A bit has been Set to the Given INDEX.
 * @n: Pointer numbers to Be changed.
 * @Index: Index of Bit HAS TO SET TO 1
 * Return: Success Always 1, IF ElSe -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
