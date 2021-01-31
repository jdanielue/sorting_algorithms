#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nodomenor, *tmp, *nodosiguiente;

	current = *list;
	tmp = current;

	while(current->next)
	{
		nodosiguiente = current->next;
		if (current->n > nodosiguiente->n)
		{
			while(tmp != NULL && nodosiguiente->n < tmp->n)
			{
				if (nodosiguiente->next != NULL && tmp->prev)
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
				else if (tmp->prev == NULL)
				{
					nodomenor = nodosiguiente;

					tmp->next = tmp->next->next;
                    nodomenor->next = tmp;
                    nodomenor->prev = NULL;
                    tmp->prev = nodomenor;
                    tmp->next->prev = tmp;
					*list =nodomenor;
					print_list(*list);
				}
				else if (nodosiguiente->next == NULL)
				{
					nodomenor = nodosiguiente;

					tmp->next = NULL;
					tmp->prev->next = nodomenor;
					nodomenor->next = tmp;
					nodomenor->prev = tmp->prev;
					tmp->prev = nodomenor;
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
