#include "main.h"
/**
 * my_getline -- gets line from standard input
 * @lineptr: double pointer
 * @size: pointer of type size_t
 * @stream: file stream
 *
 * Return: number of bytes read
 */
size_t my_getline(char **lineptr, size_t *size, FILE *stream)
{
	static char *buffer, c = 's';
	static size_t position;
	int r_val;
	size_t n = *size;
	(void)*stream;

	if (n == 0)
		n = 256;
	buffer = malloc(sizeof(char) * n);
	if (!buffer)
		return (-1);
	while (c != '\n')
	{
		r_val = read(STDIN_FILENO, &c, 1);
		if (r_val == -1)
		{
			free(buffer);
			return (-1);
		}
		if (r_val == EOF && position != 0)
		{
			position++;
			break;
		}
		if ((position + 1) >= n)
		{
			n *= 2;
			buffer = _realloc(buffer, n);
			if (!buffer)
				return (-1);
		}
		buffer[position] = c;
		position++;
	}
	buffer[position] = '\0';
	if (*lineptr == NULL)
	{
		*lineptr = malloc(position + 1);
		if (!lineptr)
			return (-1);
	}
	_strcpy(*lineptr, buffer);
	free(buffer);
	if (r_val != 0)
		position = 0;
	return (position);
}
