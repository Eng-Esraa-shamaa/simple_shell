#include "main.h"
/**
 *_strcmp - compares between two strings
 *@s1: first string
 *@s2: second string
 *Return: the result of comapre
 */
int _strcmp(char *s1, char *s2)
{
int j = 0;

while (s1[j] != '\0' && s2[j] != '\0')
{
if (s1[j] != s2[j])
{
return (s1[j] - s2[j]);
}
j++;
}
	return (0);
}
/**
 *_strdup - function used to duplicate string
 *@str: string to be duplicated
 *Return: new duplicated string
 */
char *_strdup(char *str)
{
size_t len;
char *new_str;

len = _strlen(str) + 1;
new_str = malloc(sizeof(char) * len);
if (new_str == NULL)
{
perror("malloc");
return (NULL);
}
_strcpy(new_str, str);
return (new_str);
}
/**
 *_strncat - concatenates two strings
 *@src: the source string
 * @dest: the destination string
 * @n : number of characters to be concatenated
 *Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

while (dest[i] != '\0')
{
i++;
}
while ((j < n) && (src[j] != '\0'))
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}
/**
 *_strncmp - function to compare
 *@str1: first string
 *@str2: second string
 *@n: number of equal
 *Return: zero in success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
while (n > 0)
{
if (*str1 != *str2)
return (*str1 - *str2);
if (*str1 == '\0')
return (0);
str1++;
str2++;
n--;
}
return (0);
}
