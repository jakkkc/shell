#include "shell.h"

/*Jack and Joy*/
/**
 * _memset - Func to fill memory with a constant byte
 * @s: Pointer to the memory area
 * @b: Byte to fill with *s
 * @n: Amount of Bytes to be filled
 * Return: s, Pointer to the memory area (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/*Jack and Joy*/
/**
 * ffree - Func to free Str of strs
 * @pp: Str of strs
 */
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * _realloc - Func to reallocate block of memory
 * @ptr: Pointer to previous malloc'ated block
 * @old_size: Byte size of the previous Block
 * @new_size: Byte size of the new block
 *
 * Return: Pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
