#include "main.h"
/**
 * _check_help - check help
 * @str: string
 * Return: 0
 */
int _check_help(char *str)
{
	char *copy = _strdup(str), *var = NULL;

	if (_strcmp(_strtok(copy, ' '), "help") == 0)
	{
		var = _strtok(NULL, ' ');
		if (var == NULL)
		{
			write(1, "Usage: help [BUILTIN]\nList of Built-Ins\n", 41);
			write(1, "nexit\nenv\nhelp\n", 16);
			free(copy);
			return (1);
		}
		else
		{
			while (var != NULL)
			{
				_help_case(var);
				var = _strtok(NULL, ' ');
			}
		}
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}

/**
 * _help_case - print help message
 * @var: bin name
 */
void _help_case(char *var)
{
	if (_strcmp(var, "exit") == 0)
	{
		write(1, "exit [n]\nExits the shell with a status of N.\n", 46);
	}
	else if (_strcmp(var, "help") == 0)
	{
		write(1, "help [BUILTIN]\nDisplays information for Buitlt-Ins.\n", 53);
	}
	else if (_strcmp(var, "env") == 0)
	{
		write(1, "env\nPrint all environment variables.\n", 38);
	}
	else
	{
		write(1, "Wrong Command\n", 15);
	}
}
