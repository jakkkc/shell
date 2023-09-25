#include "shell.h"

/*Jack and Joy*/
/**
 * is_chain - Func to test if Present Char in buffer is chain delimeter
 * @info: Params Structure
 * @buf: Char* buffer
 * @p: Current position of buffer address
 *
 * Return: 1, only if chain delimeter, else 0.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';') /* found end of this command */
{
buf[j] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = j;
return (1);
}

/**
 * check_chain - Func to check if we should chain based on last status
 * @info: Params structure
 * @buf: Character buffer
 * @p: Current position of buffer address
 * @i: Buffer starting position
 * @len: len(buffer)
 *
 * Return: Void()
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}

*p = j;
}

/*Jack and Joy*/
/**
 * replace_alias - Func to replace an aliases in the tokenized Str
 * @info: Params Structure
 *
 * Return: 1, only if replaced, else 0.
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/*Jack and joyy*/
/**
 * replace_vars - Func to replace varibales in tokenized Str
 * @info: Params structure
 *
 * Return: 1, only if replaced, else 0
 */
int replace_vars(info_t *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;

if (!_strcmp(info->argv[i], "$?"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&(info->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[i], _strdup(""));

}
return (0);
}

/*Jack and Joy*/
/**
 * replace_string - Func to replace Str
 * @old: The address of the old Str
 * @new: The new Str
 *
 * Return: 1, only if replaced, else 0.
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

