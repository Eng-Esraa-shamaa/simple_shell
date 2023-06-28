#include "main.h"
/**
 * free_buff_env - free buffer and variable
 * @str: string
 */
void free_buff_env(char *str)
{
	free(str);
}

/**
 * wait_free - wait and free
 * @status: status
 * @argv: free array
 * @dup: free duplicated array
 * Return: void
 */
void wait_free(int status, char **argv, char *dup)
{
	wait(&status);
	free_dup_arr(argv, dup);
}

/**
 * free_exit - free and exit
 * @str: string
 */
void free_exit(char *str)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	free(str);
	exit(0);
}
