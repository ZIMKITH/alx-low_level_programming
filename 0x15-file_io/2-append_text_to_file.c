#include "main.h"

/**
 * Append_Texts - ALL Texts to be appendend at the End.
 * @FileName: File Names And pointers,
 * @Text_Content: STRINGS have to B e added At the End of the file.
 * Return: File Name NULL, OTHERWISE -1
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
