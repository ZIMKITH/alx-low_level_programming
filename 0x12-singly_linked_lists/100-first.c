#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - Printed a sentence before  main
 * Function  EXECUTED
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
