#include "main.h"
/**
 * exec_cmd_fork -- executes command with fork
 * @command: command
 *
 * Return void
 */
void exec_cmd_fork(char *command)
{
	char *path;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return;
	}

	if (pid == 0)
	{
		path = get_path();
		exec_cmd(command, path);
		free(path);
		return;
	}
	else
	{
		wait(NULL);
	}
}
/**
 * exec_interactive_shell -- executes interactive shell
 *
 * Return: void
 */
void exec_interactive_shell(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t args;

	int should_exit = 0;

	while (!should_exit)
	{
		_puts("$ ");
		fflush(stdout);
		args = getline(&cmd, &n, stdin);
		if (args == -1)
		{
			if (args == EOF)
			{
				_putchar('\n');
				break;
			}
			else
			{
				perror("getline");
				return;
			}
		}
		cmd[_strcspn(cmd, "\n")] = '\0';
		if (_strcmp(cmd, "exit") == 0)
		{
			should_exit = 1;
		}
		else if (_strcmp(cmd, "env") == 0)
		{
			print_env();
		}
		else
		{
			exec_cmd_fork(cmd);
		}
	}
	free(cmd);
}
/**
 * exec_noninteractive_cmds -- executes non interactive
 * @input_file: string
 *
 * Return: void
 */
void exec_noninteractive_cmds(char *input_file)
{
	FILE *file = fopen(input_file, "r");
	char *line = NULL;
	size_t n = 0;
	ssize_t chars;
	int line_number = 1;
	char *path;

	if (file == NULL)
	{
		perror("Failed to open input file");
		return;
	}
	while ((chars = getline(&line, &n, file)) != -1)
	{
		line[_strcspn(line, "\n")] = '\0';
		_puts("Executing command:");
		_puts(line);
		path = get_path();
		exec_cmd(line, path);
		free(path);
		line_number++;
	}
	free(line);
	fclose(file);
}
/**
 * main -- main entry point
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: 0 success
 */
int main(int ac, char **argv)
{
	if (ac == 2)
	{
		exec_noninteractive_cmds(argv[1]);
	}
	else
	{
		exec_interactive_shell();
	}
	return (0);
}
