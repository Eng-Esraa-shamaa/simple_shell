#include "main.h"
/**
 * exec_cleanup -- frees memory of args
 * @args: double pointer
 *
 * Return: void
 */
void exec_cleanup(char **args)
{
	int i = 0;

	for (; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
/**
 * prepare_path_entry -- prepares path entry
 * @path_entry: char string
 * @path_entry_len: length of string
 * @command: char string
 *
 * Return: string
 */
char *prepare_path_entry(char *path_entry, int path_entry_len, char *command)
{
	path_entry = _realloc(path_entry, (path_entry_len + 1) * sizeof(char) + 1);
	path_entry[path_entry_len] = '/';
	path_entry[path_entry_len + 1] = '\0';
	_strncat(path_entry, command, path_entry_len + 1);
	return (path_entry);
}
/**
 * exec_path_ent -- executes path entry
 * @path_entry: string
 * @args: double pointer to args
 *
 * Return: 1 success
 */
int exec_path_ent(char *path_entry, char **args)
{
	if (executable_check(path_entry))
	{
		execve(path_entry, args, NULL);
		perror("execve");
		free(path_entry);
		exec_cleanup(args);
		return (0);
	}
	return (1);
}
/**
 * exec_cmds_path -- executes commands path
 * @args: double pointer to args
 * @path: string
 *
 * Return: void
 */
void exec_cmds_path(char **args, char *path)
{
	char *path_entry = NULL;
	int path_entry_len = 0;
	int i = 0;
	int path_len = _strlen(path);

	for (; i <= path_len; i++)
	{
		if (path[i] == ':' || i == path_len)
		{
			path_entry = prepare_path_entry(path_entry, path_entry_len, args[0]);
			if (exec_path_ent(path_entry, args) == 0)
			{
				exec_cleanup(args);
				return;
			}
			reset_path_entry(path_entry, &path_entry_len);
		}
		else
		{
			path_entry = append_path_entry(path_entry, path[i], &path_entry_len);
		}
	}
}
/**
 * exec_cmd -- executes command
 * @cmd: command
 * @path: path
 *
 * Return: int
 */
int exec_cmd(char *cmd, char *path)
{
	char **tokenized_cmd = tokenize_cmd(cmd);
	char *args[1024];

	if (exit_cmd_check(cmd))
	{
		return (1);
	}
	else if (env_cmd_check(cmd))
	{
		print_env();
		return (0);
	}
	copy_tokenized_cmd(args, tokenized_cmd);
	if (executable_check(args[0]))
	{
		exec_executable(args);
		return (0);
	}
	if (path == NULL)
	{
		path_ret_error();
		return (1);
	}

	exec_cmds_path(args, path);
	err_cmd_not_found(args[0]);
	exec_cleanup(args);
	return (1);
}

