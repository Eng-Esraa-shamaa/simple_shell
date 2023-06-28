#include "main.h"
/**
 * get_path - check file existence
 * @file_name: file name
 * Return: null
 */
char *get_path(char *file_name)
{
	char *PATH = _get_env("PATH");
	char *copy = _strdup(PATH), *conc = NULL;
	char *token = NULL, *abs = NULL;
	struct stat st;

	token = _strtok(copy, ':');
	conc = str_concat("/", file_name);
	while (token != NULL)
	{
		abs = str_concat(token, conc);
		if (stat(abs, &st) == 0)
		{
			free(PATH);
			free(copy);
			free(conc);
			return (abs);
		}
		token = _strtok(NULL, ':');
		free(abs);
	}
	free(PATH);
	free(conc);
	free(copy);
	return (NULL);
}
