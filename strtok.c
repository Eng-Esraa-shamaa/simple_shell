#include "main.h"
#include <stdbool.h>
/**
 *is_deli - function check of delimeter
 *@ch: the character
 *@deli: the delimeter
 *Return: zero on success
 */
int is_deli(char ch, const char *deli)
{
while (*deli != '\0')
{
if (ch == *deli)
{
return (1);
}
deli++;
}
return (0);
}
/**
 *_strtok - function return pointer to first string
 *@str: the string
 *@delims: the delimeter
 *Return: nothing
 */
char *_strtok(char *str, const char *delims)
{
static char *token;
char *start = NULL;
bool foundDeli = false;

if (str != NULL)
token = str;
else
{
if (token == NULL)
return (NULL);
str = token;
}
while (*str != '\0')
{
if (!foundDeli)
{
if (!is_deli(*str, delims))
{
start = str;
foundDeli = true;
}
}
else
{
if (is_deli(*str, delims))
{
*str = '\0', token = str + 1;
return (start);
}
}
str++;
}
if (start == NULL)
return (NULL);
if (!is_deli(*(str - 1), delims))
{
token = NULL;
return (start);
}
return (NULL);
}
