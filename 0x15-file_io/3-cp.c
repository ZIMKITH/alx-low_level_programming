#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void close_file(int fd);
char *create_buffer(char *file);

/**
 * create_buffer - ALLOCATED BYTES 1024 for BUFFERS.
 * @file: BUFFER FILE NAME IS storing chars.
 *
 * Return: Newly-allocated buffer TO A POINTER.
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
 * close_file - THE file descriptor is CLOSED.
 * @fd: FILE descriptor  CLOSED.
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
 * main -  CONTENTS copies of a file to another file.
 * @argc: Arguments supplied to the PROGRAM.
 * @argv: Array pointers of Arguments.
 *
 * Return: 0 SUCCESSFUL.
 *
 * Description:OR ELSE  argument count is incorrect - exit code 97.
 * If file_IF ELSE FILE DOES NOT EXIST  - exit code 98.
 * If file_to CANT BE WRITTEN - exit code 99.
 * If file_OR ELSE file_from MUST not be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

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
