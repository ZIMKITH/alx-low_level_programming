#include "main.h"

/**
 * append_text_to_file - TEXT Appended  at the end of a FILE.
 * @filename: Pointer Name of the FILE.
 * @text_content: String added to the end of the FILE.
 *
 * Return: IN CASE that the function fails or FILE NAME is NULL = -1.
 * IN CASE the file is REMOVED the user SCARCITY write permissions = -1.
 * OR ELSE - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
