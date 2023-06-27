#include "main.h"
/**
 * _concat -- concatenates two strings
 * @s1: string
 * @s2: string
 *
 * Return: string
 */
char *_concat(char *s1, char *s2)
{
	size_t len1 = _strlen(s1);
	size_t len2 = _strlen(s2);
	char *str = malloc(len1 + len2 + 1);

	if (str == NULL)
		return (NULL);

	_strcpy(str, s1);
	_strcat(str, s2);

	return (str);
}
/**
 * _unsetenv -- removes variable value form env
 * @var: string
 *
 * Return: int
 */
int _unsetenv(char *var)
{
	size_t len = _strlen(var);
	int i = 0, check = 0;

	for (; environ[i]; i++)
	{
		if (_strncmp(environ[i], var, len) == 0)
		{
			check++;
			free(environ[i]);

			while (environ[i + 1])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			break;
		}
	}
	if (check > 0)
		return (0);
	return (-1);
}
/**
 * _setenv -- sets value of a variable
 * @var: string
 * @value: string
 * @overwrite: int
 *
 * Return: int
 */
int _setenv(char *var, char *value, int overwrite)
{
	size_t len = _strlen(var), value_len;
	int i = 0, num_env = 0, j;
	char *new_variable;
	char **new_environ;

	for (; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], var, len) == 0)
		{
			if (overwrite == 0)
				return (0);
			if (overwrite == 2)
				free(environ[i]);
			break;
		}
	}
	while (environ[num_env] != NULL)
	{
		num_env++;
	}
	new_environ = malloc((num_env + 2) * sizeof(char *));
	if (new_environ == NULL)
		return (-1);
	for (j = 0; j < num_env; j++)
		new_environ[j] = environ[j];
	value_len = _strlen(value);
	new_variable = malloc(len + value_len + 2);
	if (new_variable == NULL)
	{
		free(new_environ);
		return (-1);
	}
	_strcpy(new_variable, var);
	new_variable[len] = '=';
	_strcpy(new_variable + len + 1, value);
	new_variable[len + value_len + 1] = '\0';
	new_environ[num_env] = new_variable;
	new_environ[num_env + 1] = NULL;
	environ = new_environ;
	return (0);
}
