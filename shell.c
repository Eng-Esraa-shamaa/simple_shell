#include "main.h"

/**
 * execute_shell - Executes the shell logic
 * Return: exit_val
 */
int execute_shell(void)
{
	size_t n = 0;
	int sum = 0, bin = 0, status = 0, exit_val = 0, child_pid = 0;
	char *buf = NULL, **argv = NULL, *dup = NULL;

	while (1)
	{
		_check_isatty_sig();
		sum = getline(&buf, &n, stdin);
		if (sum == -1)
			free_exit(buf);
		if (_check_ch(buf) == -1)
			continue;
		buf = _clear_buf(buf, sum);
		bin = _check_bin(buf);
		if (bin == 1)
		{
			exit_val = _get_ret(buf);
			if (exit_val >= 0)
				break;
			continue;
		}
		dup = _strdup(buf);
		argv = tokenize(dup, bin);
		if ((bin == 0 && _check_exe(argv[0]) == 0))
			child_pid = _child_fork(child_pid, argv[0]);
		else
			child_pid = 1;
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			break;
		}
		if (child_pid != 0)
			wait_free(status, argv, dup);
	}
	if (bin != 1)
		free_dup_arr(argv, dup);
	free_buff_env(buf);
	return (exit_val);
}
/**
 * main - Shell entry point
 * Return: 0 on successful execution
 */
int main(void)
{
	int exit_val = execute_shell();

	return (exit_val);
}
