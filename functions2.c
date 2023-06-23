#include "main.h"
/**
 * tokenize_cmd -- truns commands into tokens
 * @cmd: command
 *
 * Return: char
 */
char **tokenize_cmd(char *cmd)
{
	const char delim[] = " ";
	char **tokens = NULL;
	int tokens_count = 0;
	char *cmd_copy = _strdup(cmd);
	char *token = _strtok(cmd_copy, delim);

	while (token != NULL)
	{
		tokens = _realloc(tokens, (tokens_count + 1) * sizeof(char *));
		tokens[tokens_count] = _strdup(token);
		tokens_count++;
		token = _strtok(NULL, delim);
	}

	tokens = _realloc(tokens, (tokens_count + 1) * sizeof(char *));
	tokens[tokens_count] = NULL;

	free(cmd_copy);

	return (tokens);
}
/**
 * exit_cmd_check -- checks if the command is exit
 * @cmd: command
 *
 * Return: int 0 if exit
 */
int exit_cmd_check(char *cmd)
{
	return (_strcmp(cmd, "exit") == 0);
}
/**
 * env_cmd_check -- checks if the command is env
 * @cmd: command
 *
 * Return: int 0 if env
 */
int env_cmd_check(char *cmd)
{
	return (_strcmp(cmd, "env") == 0);
}
/**
 * copy_tokenized_cmd -- copies tokens
 * @args: double pointer to args
 * @tokenized_cmd: double pointer to tokens
 *
 * Return: void
 */
void copy_tokenized_cmd(char **args, char **tokenized_cmd)
{
	int i = 0;

	for (; tokenized_cmd[i] != NULL; i++)
	{
		args[i] = tokenized_cmd[i];
	}
	args[i] = NULL;
}
/**
 * executable_check -- checks if command is executable
 * @path: path
 *
 * Return: int 0 if it is executable
 */
int executable_check(char *path)
{
	return (access(path, X_OK) == 0);
}

