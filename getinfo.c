#include "shell.h"

/*Jack and Joy*/
/**
 * clear_info - Func to initialize info_t structure
 * @info: Address of structure
 */
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * set_info - Func to initialize info_t structure
 * @info: Address of the Structure
 * @av: Arg vector
 */
void set_info(info_t *info, char **av)
{
int i = 0;

info->fname = av[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

replace_alias(info);
replace_vars(info);
}
}

/*Jack and Joy*/
/**
 * free_info - Func to free info_t structure fields
 * @info: structure address
 * @all: true, only if it frees all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
info->environ = NULL;
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}

