#include "main.h"

/**
 * _check_exit - check exit
 * @str: string to be compared
 * Return: correct incorrect
 */
int _check_exit(char *str)
{
	char *copy = _strdup(str);

	if (_strcmp(_strtok(copy, ' '), "exit") == 0)
	{
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}

/**
 * _check_env - check env
 * @str: string to be compared
 * Return: correct incorrect
 */
int _check_env(char *str)
{
	char *copy = _strdup(str);

	if (_strcmp(_strtok(copy, ' '), "env") == 0)
	{
		free(copy);
		_print_env();
		return (1);
	}
	free(copy);
	return (0);
}
