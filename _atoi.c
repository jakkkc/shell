#include "shell.h"

/**
 * interactive - Func to return true whn shell is interactive mode
 * @info: structure address
 *
 * Return: 1 only if interactive mode, else 0
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Func to check if char is a delimeter
 * @c: the character to check
 * @delim: the delimeter Str
 * Return: 1 only if true, else 0
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (0);
}

/**
 * _isalpha - Func to check for alphabetic Char
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - Func to conv Str to Int
 * @s: Str to be conv
 * Return: 0 only if no numbers in Str, else converted number
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}

