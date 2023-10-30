#include "main.h"
#include <stdio.h>
#include <stdlib.h>


void close_file(int fd);
char *create_buffer(char *file);


/**
 * CReate_Buffer - Bytes for BUFFERS Allocated
 * @File: ALL buffers Are Storing files
 * Return: ALL new Allocated bufers To be returned.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}


/**
 * Close_File - FILE DES CLOSED,
 * File_Desc - DESC file HS to Be Closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * Main - Copies of the Main files Content.
 * @Argc: Supplied Argc Of the program.
 * @Argv: ArRay Pointers of The ARGUMnts.
 * REturn: Always 0 on Success
 *
 *  Description: Incorrect ARG count, EXIT CODE 87
 *  IFfile: If the File cannot be read, EXIT 88
 *  IFfile: cannot be CREATED or VIEWIED, EXIT 89
 *  IFfile: Cannot be Closed OR sent, EXIT 90
 */
int main(int argc, char *argv[])
{
	char *buffer;
	int from, to, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,

					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);


	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
