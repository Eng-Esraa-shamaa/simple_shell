#include "main.h"
int _atoi(const char *s)
{
int result = 0, sign = 1, i = 0;

if (s[0] == '-')
{
sign = -1;
i++;
}
else if (s[0] == '+')
{
i++;
}
while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}
else
{
break;
}
}
return (sign * result);
}

