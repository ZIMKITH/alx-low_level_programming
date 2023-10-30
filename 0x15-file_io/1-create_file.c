#include "main.h"

/**
 * Create_File - FIles has to be Created.
 * @FileName: Names of the files To be Created.
 * @Text_Content: Dish up content to a Pointer, Write on files.
 * Return: ALWAYS if close to success +-1, Failure -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}


	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
