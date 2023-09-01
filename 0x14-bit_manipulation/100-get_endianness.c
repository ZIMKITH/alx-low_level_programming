#include "main.h"

/**
 * get_endianness - Strutinize if a machine is smaller or bigger endian
 * Return: 0 FOR Bigger, 1 FOR Smaller
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
