#include "shell.h"

/*Jack and Joy*/
/**
 **_strncpy - Func to copy a string
 *@dest: Destination Str to be copied to
 *@src: Source Str
 *@n: the amount of Char to be copied
 *Return: Concatenated Str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/*JAcks and joy*/
/**
 **_strncat - Func to concatenate 2 Str
 *@dest: 1st Str
 *@src: 2nd Str
 *@n: Amount of bytes to be maximally used
 *Return: Concatenated Str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - Func locates a character in a string
 *@s: Str to be parsed
 *@c: Char to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

