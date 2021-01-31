#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *nodomenor, *tmp = current, *nodosiguiente;

	current = *list;
	tmp = current;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (current->next)
	{
		nodosiguiente = current->next;
		if (nodosiguiente->n < current->n)
		{
			while (tmp != NULL && nodosiguiente->n < tmp->n)
			{
				if (nodosiguiente->next != NULL && tmp->prev != NULL)
				{
					nodomenor = nodosiguiente;
					tmp->next = tmp->next->next;
					tmp->prev->next = nodomenor;
					nodomenor->next = tmp;
					nodomenor->prev = tmp->prev;
					tmp->prev = nodomenor;
					tmp->next->prev = tmp;
					print_list(*list);
				}
				else if (tmp->prev == NULL && nodosiguiente->next != NULL)
				{
					nodomenor = nodosiguiente;
					tmp->next = tmp->next->next;
					nodomenor->next = tmp;
					nodomenor->prev = NULL;
					tmp->prev = nodomenor;
					tmp->next->prev = tmp;
					*list = nodomenor;
					print_list(*list);
				}
				else if (nodosiguiente->next == NULL && tmp->prev != NULL)
				{
					nodomenor = nodosiguiente;
					tmp->next = NULL;
					tmp->prev->next = nodomenor;
					nodomenor->next = tmp;
					nodomenor->prev = tmp->prev;
					tmp->prev = nodomenor;
					print_list(*list);
				}
				else if (nodosiguiente->next == NULL && tmp->prev == NULL)
				{
					nodomenor->prev->next = nodomenor->next;
					nodomenor->next = nodomenor->prev;
					nodomenor->prev = nodomenor->prev->prev;
					nodomenor->next->prev = nodomenor;
					*list = nodomenor;
					print_list(*list);
				}
			tmp = nodosiguiente->prev;
			}
			tmp = current;
		}
		else
		{
			current = current->next;
			tmp = current;
			tmp = current;
		}
	}
}
