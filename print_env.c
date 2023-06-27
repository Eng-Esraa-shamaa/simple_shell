#include "main.h"
/**
 *_getenv - function to get env
 *@var: variable
 *Return: nothing
 *
 */
char *_getenv(char *var)
{
char **env;
size_t var_len = _strlen(var);
char *env_entry;

if (var == NULL)
{
exit(1);
}
for (env = environ; *env != NULL; env++)
{
env_entry = *env;
if (_strncmp(env_entry, var, var_len) == 0 && env_entry[var_len] == '=')
{
return (_strdup(env_entry + var_len + 1));
}
}
return (NULL);
}
/**
 *print_env - print the environment
 *Return: nothing
 */
void print_env(void)
{
char **env = environ;

while (*env != NULL)
{
_puts(*env);
putchar('\n');
env++;
}
}
