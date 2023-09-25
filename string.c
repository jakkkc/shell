#include "shell.h"

/*Jack and Joy*/
/**
 * _strlen - Func to return len(String)
 * @s: Str whose len to check
 *
 * Return: Int len of Str
 */
int _strlen(char *s)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;

return (i);
}

/*Jack and Joy*/
/**
 * _strcmp - Func to perform lexicogarphic comparison of 2Strs.
 * @s1: 1st Str
 * @s2: 2nd Str
 *
 * Return: if s1 < s2: (-)ve,elif s1 > s2: (+)ve, else 0
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Func to check if needle starts with haystack
 * @haystack: Str to check
 * @needle: Substring to check
 *
 * Return: Next character address.
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - Func to concatenate 2Str
 * @dest: Destination buffer
 * @src: Source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
