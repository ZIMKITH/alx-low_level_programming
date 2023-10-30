#include "main.h"
#include <stdlib.h>

/**
 * Read_Textfile - All Text Files has to be read carefully and clearely.
 * @Filename: FILE name Revealed
 * @Letters: All THE letters to be read 1 by 1
 * Return: ATTESTED names and numbers has to be printed. file name id NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	char *buf;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);


	free(buf);
	close(fd);
	return (w);
}
