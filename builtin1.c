#include "shell.h"

/*Jac and Joy*/
/**
 * _myenv - Func to print the current env
 * @info: Struct that contains potential args. Used in maintaining
 *          CONST Func prototype.
 * Return: 0 all the time
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - Func to get value of an env var
 * @info: Struct that contains potential args
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
 * _mysetenv - Func to Initialize new env var,
 *             or modify an existing one
 * @info: Struct to contain potential args. Used in maintaining
 *        CONST Func prototype.
 *  Return: 0 all the time
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - Func to Remove an env var
 * @info: Struct to contain potential args. Used in maintaining
 *        CONST func prototype.
 * Return:0 all the time
 */
int _myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
 * populate_env_list - Func to populate env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return:0 all the time
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}

