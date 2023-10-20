#include "sort.h"
/**
 * insertion_sort_list - function that thats sorts a set
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *node;
if (list == NULL || (*list)->next == NULL)
return;
node = (*list)->next;
while (node)
{
while ((node->prev) && (node->prev->n > node->n))
{
node = swap_node(node, list);
print_list(*list);
}
node = node->next;
}
}
/**
 *swap_node - function that swaps a node
 *@node: node
 *@list: list
 *Return: now
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *ret = node->prev, *now = node;
ret->next = now->next;
if (now->next)
now->next->prev = ret;
now->next = ret;
now->prev = ret->prev;
ret->prev = now;
if (now->prev)
now->prev->next = now;
else
*list = now;
return (now);
}
