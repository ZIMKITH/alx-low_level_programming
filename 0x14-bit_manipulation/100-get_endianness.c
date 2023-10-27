#include "main.h"

/**
 * Get_Endianness - Endian Machine To be Checked.
 * Return: Always 1 for SMAll, 0 For Huge.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
