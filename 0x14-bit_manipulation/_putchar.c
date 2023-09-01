#include "main.h"
#include <unistd.h>
/**
 * _putchar - Written character c to STDOUT
 * @c: PRINTED Character
 *
 * Return: Successful 1.
 * Error,  Return -1, Set error Appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

