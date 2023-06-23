#include "main.h"
/**
 *_strcspn - function implem to strcspn
 *@str: the string
 *@ch: the character
 *Return: count
 */
size_t _strcspn(const char *str, const char *ch)
{
const char *p, *q;
size_t count = 0;

for (p = str; *p != '\0'; p++)
{
for (q = ch; *q != '\0'; q++)
{
if (*p == *q)
{
return (count);
}
}
count++;
}
return (count);
}
