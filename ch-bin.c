#include "main.h"

/**
 * _check_ch - check character
 * @str: string
 * Return: ch
 */
int _check_ch(char *str)
{
	int n, ch = -1;

	if (str[0] == '#')
		return (ch);
	for (n = 0; str[n]; n++)
	{
		if (str[n] != 32 && str[n] != 10 && str[n] != '\t' && str[n] != '#')
		{
			ch = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = _strtok(str, ' ');
			}
			break;
		}
		if (str[n] == '#')
			break;
	}
	return (ch);
}

/**
 * _check_bin - check builtin
 * @str: string
 * Return: 0
 */
int _check_bin(char *str)
{
	if (_check_exit(str) == 1)
		return (1);
	if (_check_env(str) == 1)
		return (3);
	return (0);
}
