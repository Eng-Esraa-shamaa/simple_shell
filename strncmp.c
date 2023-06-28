#include "main.h"
/**
 *_strncmp - compare two strings
 *@str1: first string
 *@str2: second string
 *@n: number
 *Return: 0 (success)
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

