#include "main.h"

/**
 * tokenize - tokenize string
 * @str: string to be tokenized
 * @bin: builtin
 * Return: tokenized strings array
 */
char **tokenize(char *str, int bin)
{
	char *tok = NULL, **arr = NULL, *check = NULL;
	int length = 0, n = 0;
	struct stat st = {0};

	length = args(str);
	arr = malloc(sizeof(char *) * (length + 1));
	if (arr == NULL)
		return (NULL);
	tok = _strtok(str, ' ');
	for (n = 0; tok != NULL; n++)
	{
		arr[n] = _strdup(tok);
		tok = _strtok(NULL, ' ');
	}
	if (bin == 0 && arr[0][0] != '/')
	{
		check = get_path(arr[0]);
		if (check != NULL)
		{
			free(arr[0]);
			arr[0] = _strdup(check);
		}
		else
		{
			if ((stat(arr[0], &st) == 0) || (_check_dir(arr[0]) == 0))
				;
			else
				perror(arr[0]);
		}
		free(check);
	}
	arr[n] = NULL;
	return (arr);
}
