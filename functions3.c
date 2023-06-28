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
	str = _check_com(str);
	return (str);
}
/**
 * _check_com - check comment
 * @str: string
 * Return: str
 */
char *_check_com(char *str)
{
	int n = 0, m = 0, o = 0, check = 0;

	while (str[m])
	{
		if (str[m] == ' ' && str[m + 1] == '#')
		{
			o++;
			break;
		}
		m++;
	}
	if (o == 0)
		return (str);
	while (str[n])
	{
		if (check == 1)
		{
			str[n] = ' ';
			n++;
			continue;
		}
		if (str[n] == ' ' && str[n + 1] == '#')
		{
			check++;
			n++;
			continue;
		}
		n++;
	}
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
