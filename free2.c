#include"main.h"
/**
 * free_dup_arr - free duplicated array
 * @arr: free array
 * @dup: free duplicated array
 */
void free_dup_arr(char **arr, char *dup)
{
	int n;

	for (n = 0; arr[n] != NULL; n++)
	{
		free(arr[n]);
	}
	free(arr[n]);
	free(arr);
	free(dup);
}

/**
 * free_env - free env
 * @var: variable name
 * Return: asd
 */
void free_env(char *var)
{
	size_t length = 0;
	int n;

	length = _strlen(var);
	for (n = 0; environ[n] != NULL; n++)
	{
		if (_strncmp(environ[n], var, length) == 0)
		{
			free(environ[n]);
		}
	}
}
