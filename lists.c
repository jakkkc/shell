#include "shell.h"

/*Jack and Joy*/
/**
 * add_node - Func to add a node to the start of the ls
 * @head: Pointer address of the Head node
 * @str: String field of node
 * @num: node index used by the Hist
 *
 * Return: The Size of List
 */
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;

if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}

/**
 * add_node_end - Func to add a node to the end of the list
 * @head: Pointer's address of the head node
 * @str: String field of node
 * @num: node index used by Hist
 *
 * Return: The Size of the list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);

node = *head;

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}

/*Jack and Joy*/
/**
 * print_list_str - Func to print string elements of list_t linked list
 * @h: Pointer pointing to first node
 *
 * Return: The size of the list
 */
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/*Jack and Joy*/
/**
 * delete_node_at_index - Func to delete node at an index
 * @head: Pointer address to first node
 * @index: The Index of the node to delete
 *
 * Return: 1 only if successful, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!head || !*head)
return (0);

if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}

/*Jack and Joy*/
/**
 * free_list - Func to free all the nodes of list
 * @head_ptr: Address of the pointer to head node
 *
 * Return: Void()
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;

if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}

