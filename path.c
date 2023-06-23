#include "main.h"
/**
 *print_directories - function print dirs
 *@path: path
 *Return: nothing
 */
void print_directories(char *path)
{
char *path_copy = _strdup(path);
char *token = _strtok(path_copy, ":");

while (token != NULL)
{
/*printf("%s\n", token);*/
_puts(token);
_putchar('\n');
token = _strtok(NULL, ":");
}
free(path_copy);
}
/**
 *build_directory_ls - function build dirs
 *@path: path
 *Return: head
 *
 */
Node *build_directory_ls(char *path)
{
Node *head = NULL;
Node *tail = NULL;
char *path_copy = _strdup(path);
char *token = _strtok(path_copy, ":");

while (token != NULL)
{
Node *node = (Node *)malloc(sizeof(Node));
node->directory = _strdup(token);
node->next = NULL;
if (head == NULL)
{
head = node;
tail = node;
}
else
{
tail->next = node;
tail = node;
}
token = _strtok(NULL, ":");
}
free(path_copy);
return (head);
}
/**
 *get_path - function gets a path
 *Return: the path
 */
char *get_path()
{
char *path = _getenv("PATH");
if (path == NULL)
{
_puts("Failed to retrieve PATH");
_putchar('\n');
return (NULL);
}
return (_strdup(path));
}
