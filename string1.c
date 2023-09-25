#include "shell.h"

/*Jack and Joy*/
/**
 * _strcpy - Func to copy Str
 * @dest: Destination of copied
 * @src: Source of the copied
 *
 * Return: Pointer pointing to @dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/*Jack and Joy*/
/**
 * _strdup - Func to duplicate a Str
 * @str: Str to be duplicated
 *
 * Return: Pointer pointing to the duplicated Str
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/*JAck and Joy*/
/**
 * _puts - Func that prints an input Str
 * @str: Str to be printed
 *
 * Return: Nan / Process
 */
void _puts(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/*Jack and Joy*/
/**
 * _putchar - Func to write Char c to stdout
 * @c: Char to print
 *
 * Return: 1, if successful
 * On error, -1 is returned, && errno is set appropriately.
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
