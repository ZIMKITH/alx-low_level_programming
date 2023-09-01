#include "main.h"

/**
 * flip_bits - Counted  numbers of bits to be changed
 * To get from point A to point B
 * @n: Number One
 * @m: Number Two
 *
 * Return: Bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
