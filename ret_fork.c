#include "main.h"
/**
 * _child_fork - fork child
 * @child_pid: child process id
 * @pro: program name
 * Return: child process id
 */
int _child_fork(pid_t child_pid, char *pro)
{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(pro);
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}

/**
 * _get_ret - get return value
 * @str: string
 * Return: exit value
 */
int _get_ret(char *str)
{
	char *copy = _strdup(str), *tok;
	int exit_val = 0;

	tok = _strtok(copy, ' ');
	tok = _strtok(NULL, ' ');
	if (tok == NULL)
	{
		free(copy);
		return (0);
	}
	if (_check_dig(tok) == 0)
		exit_val = _atoi(tok);
	else
	{
		free(copy);
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		return (-1);
	}
	free(copy);
	if (exit_val < 0)
	{
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		exit_val = (-1);
	}
	return (exit_val);
}
