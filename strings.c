#include "main.h"
/**
 *_strlen - used to length the string
 *@s: is the string to length it
 *Return: zero
 */
int _strlen(char *s)
{
int i = 0;

while (*s != '\0')
{
i++;
s++;
}
return (i);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 *_puts - used to print string
 *@str: is the string to be printed
 *Return: zero
 */
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str++);
}
}
/**
 *_strcpy - function to copy the string
 *@dest: the first string
 *@src: the string to be copied into dest
 *Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int x;

for (x = 0; src[x] != '\0'; x++)
{
dest[x] = src[x];
}
dest[x++] = '\0';
return (dest);
}
/**
 *_strcat - function to concatenate two strings
 *@dest: the destination string
 *@src: the source string
 *Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;

while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0')
{
dest[i] = src[j];
j++;
i++;
}
dest[i] = '\0';
return (dest);
}
