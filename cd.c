#include "main.h"
/**
 * cd_cmd - changes the current directory
 * @args: command arguments
 *
 * Return: void
 */
void cd_cmd(char **args)
{
char *new_dir, *current_dir, *pwd;

if (args[1] == NULL || _strcmp(args[1], "~") == 0)
new_dir = _getenv("HOME");
else if (_strcmp(args[1], "-") == 0)
new_dir = _getenv("OLDPWD");
else
new_dir = args[1];
if (new_dir == NULL)
{
perror("cd");
return;
}
current_dir = getcwd(NULL, 0);
if (current_dir == NULL)
{
perror("cd");
free(new_dir);
return;
}
if (chdir(new_dir) == -1)
{
perror("cd");
free(new_dir);
free(current_dir);
return;
}
free(new_dir);
if (_setenv("OLDPWD", current_dir, 1) == -1)
{
perror("cd");
}
free(current_dir);
pwd = getcwd(NULL, 0);
if (pwd != NULL)
{
if (_setenv("PWD", pwd, 1) == -1)
perror("cd");
free(pwd);
}
}
