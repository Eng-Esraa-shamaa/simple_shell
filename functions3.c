#include "main.h"
/**
 * exec_executable -- executes an executable command
 * @args: double pointer
 *
 * Return: void
 */
void exec_executable(char **args)
{
	execve(args[0], args, environ);
	perror("execve");
}
/**
 * path_ret_error -- prints path retrival erro
 *
 * Return: void
 */
void path_ret_error(void)
{
	write(STDERR_FILENO, "Failed to retrieve PATH\n", 24);
}
/**
 * reset_path_entry -- resets the path
 * @path_entry: string
 * @path_entry_len: pointer to length of the string
 *
 * Return: void
 */
void reset_path_entry(char *path_entry, int *path_entry_len)
{
	path_entry[0] = '\0';
	*path_entry_len = 0;
}
/**
 * append_path_entry -- appends the path
 * @path_entry: string
 * @path_ch: char
 * @path_entry_len: pointer to length of string
 *
 * Return: char
 */
char *append_path_entry(char *path_entry, char path_ch, int *path_entry_len)
{
	path_entry = _realloc(path_entry, (*path_entry_len + 1) * sizeof(char) + 1);
	path_entry[*path_entry_len] = path_ch;
	path_entry[*path_entry_len + 1] = '\0';
	(*path_entry_len)++;
	return (path_entry);
}
/**
 * err_cmd_not_found -- prints command not found error
 * @command: string of characters
 *
 * Return: void
 */
void err_cmd_not_found(char *command)
{
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": command not found", 19);
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}
