#include "main.h"

/**
 * get_bit - Returned the VALUE of a bit to an index in a DECIMAL number
 * @n: NUMBERS  searched
 * @index: BIT index
 *
 * Return: Value of an INDEX bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
