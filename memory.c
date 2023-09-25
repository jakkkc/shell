#include "shell.h"

/*Jack && Joy*/
/**
 * bfree - Func to free Pointer then sets address to NULL
 * @ptr: setting the address of the Pointer to free
 *
 * Return: 1 if successfully freed, esle 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}

