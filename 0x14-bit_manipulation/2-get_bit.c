#include "main.h"

/**
 * Get_bit - Decimal number  Returned a utility of a bit to an index.
 * @n: Searching for  A NUMBER.
 * @index: Segment Of the Index.
 * Return: Value ReturneD
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
