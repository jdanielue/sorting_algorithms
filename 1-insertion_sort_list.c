#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);

			/*if (current->next != NULL && current->prev->prev != NULL)
			{
				//current->prev->next = current->next;
				current->prev->prev->next = current;
				current->next = current->prev;
				current->prev = current->next->prev;
				current->next->prev = current;
				current->next->next->prev = current->next;
				print_list(*list);
			}
			else if (current->prev->prev == NULL && current->next != NULL)
			{
				//current->prev->next = current->next;
				current->next = current->prev;
				current->prev = NULL;
				current->next->prev = current;
				current->next->next->prev = current->next;
				*list = current;
				print_list(*list);
			}
			else if (current->next == NULL && current->prev->prev != NULL)
			{
				//current->prev->next = current->next;
				current->prev->prev->next = current;
				current->next = current->prev;
				current->prev = current->next->prev;
				current->next->prev = current;
				print_list(*list);
			}
			else if (current->next == NULL && current->prev->prev == NULL)
			{
				//current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->next->prev = current;
				*list = current;
				print_list(*list);
			}*/
		}
		current = current->next;
	}
}
