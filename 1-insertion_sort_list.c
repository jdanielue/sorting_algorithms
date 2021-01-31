#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nodomenor, *tmp, *nodosiguiente, *pa_atras;

	current = *list;
	tmp = current;
	pa_atras = current;

	while(current->next)
	{
		nodosiguiente = current->next;
		if (current->n > nodosiguiente->n)
		{
			while(pa_atras != NULL && nodosiguiente->n < pa_atras->n)
			{
				if (nodosiguiente->next != NULL)
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
				else
				{
					nodomenor = nodosiguiente;

					tmp->next = tmp->next->next;
					tmp->prev->next = nodomenor;
					nodomenor->next = NULL;
					nodomenor->prev = tmp->prev;
					tmp->prev = nodomenor;
					print_list(*list);
				}
			pa_atras = nodosiguiente->prev;

			}
			pa_atras = current;

		}
		else
		{
			current = current->next;
			pa_atras = current;
			tmp = current;
		}
	}
}
