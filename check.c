#include "main.h"

/**
 * _check_exe - check executable
 * @path: file route
 * Return: 0
 */
int _check_exe(char *path)
{
	if (_check_dir(path) == 0)
	{
		if (path[0] == '/')
			perror(path);
		else
			perror(path);
		return (1);
	}
	if (access(path, X_OK))
		return (2);
	else
		return (0);
}

/**
 * _check_dir - check directory
 * @path: file route
 * Return: check directory or not
 */
int _check_dir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}

/**
 * _check_dig - check digit
 * @str: string
 * Return: check
 */
int _check_dig(char *str)
{
	int n = 0, check = 0;

	while (str[n])
	{
		if (str[n] >= 48 && str[n] <= 57)
		{
			n++;
			continue;
		}
		else
		{
			check++;
			break;
		}
	}
	return (check);
}
