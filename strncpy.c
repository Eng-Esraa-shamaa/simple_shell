#include "main.h"
/**
 *_strncpy - copy the string
 *@dest: the string dest
 *@src: the string src
 *@n: the numbers of characters
 *Return: the pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}
for (; i < n; i++)
{
dest[i] = '\0';
}
return (dest);
}
