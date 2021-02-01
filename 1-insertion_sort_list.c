#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: Pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *nodomenor = NULL, *tmp = NULL, *nodosiguiente = NULL;

	current = (*list)->next; //current = *list;
	//tmp = current;
	(void) nodomenor;
	(void) tmp;
	(void) nodosiguiente;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)//while (current->next)
	{
		//nodosiguiente = current->next;
		//if (current->n < current->prev->n)//if (nodosiguiente->n < current->n)
		//{
			while (current->prev != NULL && current->n < current->prev->n)//while (tmp != NULL && nodosiguiente->n < tmp->n)
			{
				if (current->next != NULL && current->prev->prev != NULL)//(nodosiguiente->next != NULL && tmp->prev != NULL)
				{
					//nodomenor = nodosiguiente; es == a current mio actual
					current->prev->next = current->next;//tmp->next = tmp->next->next;
					current->prev->prev->next = current;//tmp->prev->next = nodomenor;
					current->next = current->prev;//nodomenor->next = tmp;
					current->prev = current->next->prev;//nodomenor->prev = tmp->prev;
					current->next->prev = current;//tmp->prev = nodomenor;
					current->next->next->prev = current->next;//tmp->next->prev = tmp;
					print_list(*list);
				}
				else if (current->prev->prev == NULL && current->next != NULL)//(tmp->prev == NULL && nodosiguiente->next != NULL)
				{
					//nodomenor = nodosiguiente;
					current->prev->next = current->next;//tmp->next = tmp->next->next;
					current->next = current->prev;//nodomenor->next = tmp;
					current->prev = NULL;//nodomenor->prev = NULL;
					current->next->prev = current;//tmp->prev = nodomenor;
					current->next->next->prev = current->next;//tmp->next->prev = tmp;
					*list = current;//*list = nodomenor;
					print_list(*list);
				}
				else if (current->next == NULL && current->prev->prev != NULL)//(nodosiguiente->next == NULL && tmp->prev != NULL)
				{
					//nodomenor = nodosiguiente;
					current->prev->next = current->next;//tmp->next = NULL;
					current->prev->prev->next = current;//tmp->prev->next = nodomenor;
					current->next = current->prev;//nodomenor->next = tmp;
					current->prev = current->next->prev;//nodomenor->prev = tmp->prev;
					current->next->prev = current;//tmp->prev = nodomenor;
					print_list(*list);
				}
				else if (current->next == NULL && current->prev->prev == NULL)//(nodosiguiente->next == NULL && tmp->prev == NULL)
				{
					current->prev->next = current->next;//nodomenor->prev->next = nodomenor->next;
					current->next = current->prev;//nodomenor->next = nodomenor->prev;
					current->prev = current->prev->prev;//nodomenor->prev = nodomenor->prev->prev;
					current->next->prev = current;//nodomenor->next->prev = nodomenor;
					*list = current;//*list = nodomenor;
					print_list(*list);
				}
			//tmp = nodosiguiente->prev;
			}
			//tmp = current;
		//}
		//else
		//{
			current = current->next;
			//tmp = current;
			//tmp = current;
		//}
	}
}
