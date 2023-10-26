#include "main.h"
#include <unistd.h>
/**
 * _Putchar - Character c has been put to standard Output.
 * @c: The Printed Char c.
 *
 * Return: Success always 1
 * On Error: Error is set adequately, Return -1 Always.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
