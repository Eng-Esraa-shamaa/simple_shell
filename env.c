#include "main.h"

/**
 * _print_env - print environment variables
 */
void _print_env(void)
{
	int n;

	for (n = 0; environ[n]; n++)
	{
		write(1, environ[n], _strlen(environ[n]));
		write(1, "\n", 1);
	}
}

/**
 * _get_env - Uses the environ variable in order to get a variable
 * @var: variable name
 * Return: Returns the value of the variable or NULL
 */
char *_get_env(const char *var)
{
	char *token, *value, *copy;
	size_t n = 0;

	if (var == NULL)
		exit(1);
	for (; environ[n] != NULL; n++)
	{
		copy = _strdup(environ[n]);
		token = _strtok(copy, '=');
		if (_strcmp(var, token) == 0)
		{
			token = _strtok(NULL, '=');
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (value == NULL)
			{
				free(copy);
				return (NULL);
			}
			_strcpy(value, token);
			free(copy);
			break;
		}
		free(copy);
	}
	return (value);
}
