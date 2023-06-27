#include "main.h"
/**
 *execute_setenv - function to exc setenv
 *@tokenized_cmd: command
 *Return: void
 */
void execute_setenv(char **tokenized_cmd)
{
char *variable = tokenized_cmd[1];
char *value = tokenized_cmd[2];

_setenv(variable, value, 1);
}
/**
 *execute_unsetenv - function to esc unsetenv
 *@tokenized_cmd: command
 *Return: void
 */
void execute_unsetenv(char **tokenized_cmd)
{
char *variable = tokenized_cmd[1];

_unsetenv(variable);
}
/**
 *exec_cmd - function to excutes command
 *@cmd: command
 *@path: the path
 *Return: zer or oneo
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
else if (_strcmp(cmd, "cd") == 0)
{
cd_cmd(tokenized_cmd);
return (0);
}
else if (_strcmp(cmd, "setenv") == 0)
{
execute_setenv(tokenized_cmd);
exec_cleanup(args);
return (0);
}
else if (_strcmp(cmd, "unsetenv") == 0)
{
execute_unsetenv(tokenized_cmd);
exec_cleanup(args);
return (0);
}
copy_tokenized_cmd(args, tokenized_cmd);
if (exec_builtin_or_exec(args, path))
return (0);
path_ret_error();
return (1);
}
/**
 *exec_builtin_or_exec - function to excute
 *@args: argumenets
 *@path: path
 *Return: 0
 */
int exec_builtin_or_exec(char **args, char *path)
{
if (executable_check(args[0]))
{
exec_executable(args);
return (1);
}
if (path == NULL)
{
exec_cleanup(args);
return (0);
}
exec_cmds_path(args, path);
err_cmd_not_found(args[0]);
exec_cleanup(args);
return (1);
}
