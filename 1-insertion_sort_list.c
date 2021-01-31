#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nodomenor, *tmp, *pa_atras;

	current = *list;
	tmp = current;

	while(current)
	{
		nodomenor = current->next;
		if (current->n > nodomenor->n)
		{
			while(tmp != NULL && nodomenor->n < tmp->n)
				tmp = tmp->prev;

			nodomenor->prev->next = nodomenor->next;
			nodomenor->next->prev = nodomenor->prev;

			nodomenor-> prev = tmp->prev;
			nodomenor-> next= tmp;

			tmp->prev = nodomenor;
			tmp->prev->next = nodomenor;

		}
		tmp = current;
		current = current->next;
	}
}