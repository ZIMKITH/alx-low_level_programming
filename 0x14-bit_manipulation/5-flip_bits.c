#include "main.h"

/**
 * Flip_Bits - Counted numbers Of bits to Change, from A to another.
 * @n: Number that Counts
 * @m: Second Number To BE Counted.
 * Return: CHanged Numbers To BiTs.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	unsigned long int exclusive = n ^ m;
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
