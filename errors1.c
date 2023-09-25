#include "shell.h"

/*Jac and Joy*/
/**
 * _eputs - Func to print an input Str
 * @str: Str to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - Func to write Char c to stderr
 * @c: Char to print
 *
 * Return: 1, only if successful
 * On error, -1, and errno is set appropriately.
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - Func to write Char c to given fd
 * @c: Char to print
 * @fd: Fd to write to
 *
 * Return: 1, only if successful.
 * On error, -1, && errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putsfd - Func to print an input Str
 * @str: Str to print
 * @fd: the filedescriptor to write to
 *
 * Return: the no. of charaters to be put
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
