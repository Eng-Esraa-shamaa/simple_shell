#include "main.h"
/**
 * _check_isatty_sig - check signal isatty
 */
void _check_isatty_sig(void)
{
	signal(SIGINT, _sh);
	if ((isatty(STDIN_FILENO) == 1))
		write(STDOUT_FILENO, "$ ", 3);
}
/**
 * _clear_buf - remove '\n'
 * @str: string
 * @sum: string length
 * Return: str
 */
char *_clear_buf(char *str, int sum)
{
	str[sum - 1] = '\0';
	str = _search_remove(str);
	return (str);
}
/**
 * _search_remove - search remove
 * @str: string
 * Return: str
 */
char *_search_remove(char *str)
{
	int n, m = 0;

	for (n = 0; str[n]; n++)
	{
		if (str[n] == '\t')
		{
			m++;
		}
	}
	if (m > 0)
	{
		for (n = 0; str[n]; n++)
		{
			if (str[n] == '\t')
			{
				str[n] = ' ';
			}
		}
	}
	return (str);
}
