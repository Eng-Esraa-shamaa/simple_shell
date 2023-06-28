#include "main.h"

/**
 * _sh - signal handler ^C
 * @sn: signal number
 */
void _sh(int sn)
{
	(void)sn;
	write(STDOUT_FILENO, "\n$ ", 4);
}

/**
 * args - count arguments
 * @str: string
 * Return: sum
 */
int args(char *str)
{
	int n, sum = 0;

	if (str[0] != ' ')
		sum++;
	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		sum++;
	for (n = 1; str[n]; n++)
	{
		if (str[n] == ' ' && (str[n + 1] != ' ' && str[n + 1] != '\0'))
			sum++;
	}
	return (sum);
}
