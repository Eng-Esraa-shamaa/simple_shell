#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: string
 * @src: string
 *
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strncpy - copies a string
 * @dest: string destination
 * @src: string source
 * @n: int
 *
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, a = 0;

	for (i = 0; i < n; i++)
	{
		if (src[i] == '\0')
			a = 1;
		if (a == 0)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
		}
	}

	return (dest);
}
/**
 * str_concat - Concatenates two strings
 * @s1: string
 * @s2: string
 *
 * Return: concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, n = 0;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	do {
		i++;
	} while (s1[i - 1]);
	do {
		j++;
	} while (s2[j - 1]);
	str = malloc(sizeof(char) * (i + j - 1));
	if (str == NULL)
		return (NULL);

	for (n = 0; n < i; n++)
		str[n] = s1[n];
	for (n = 0; n < j; n++)
		str[n + i - 1] = s2[n];
	return (str);
}
/**
 * _strcmp - compares two strings
 * @s1: String
 * @s2: String
 *
 * Return: int
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, ss1 = 0, ss2 = 0, result = 0;

	for (i = 0; i > -1; i++)
	{
		if (s1[i] != s2[i])
		{
			ss1 = s1[i];
			ss2 = s2[i];
			break;
		}
		else
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				break;
		}
	}
	result = ss1 - ss2;
	return (result);
}

/**
 * _atoi - converts string to int
 * @s: string to be converted
 *
 * Return: int
 */
int _atoi(char *s)
{
	char c;
	unsigned int i, n = 0, j = _strlen(s) - 1, null = -1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = s[i];
		if (c == '-')
			sign *= -1;
		if (c >= 48 && c <= 57)
		{
			n = n * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c >= 48 && c <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (j == null)
		return (0);
	return (n);
}
