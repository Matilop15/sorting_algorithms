#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: no sabemos
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual = NULL, *ptr = NULL, *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	actual = (*list)->next;
	while (actual != NULL)
	{
		ptr = actual;
		actual = actual->next; /*hasta el final de la lista*/
		if (ptr->n < ptr->prev->n)
		{
			tmp = ptr->prev;
			while (tmp != NULL && tmp->n > ptr->n) /*empezamos a comparar*/
			{
				tmp->next = ptr->next;
				if (ptr->next !=  NULL)
					ptr->next->prev = ptr->prev;
				if (tmp->prev == NULL) /*este es el nodo mas pequeño*/
				{
					ptr->prev = NULL;
					ptr->next = tmp;
					ptr->next->prev = ptr;
					*list = ptr;
					print_list(*list);
					break;
				}
				else
				{
					tmp->prev->next = ptr;
					ptr->prev = tmp->prev;
					tmp->prev = ptr;
					ptr->next = tmp;
					print_list(*list);
				}
				tmp = tmp->prev->prev;
			}
		}
	}
}
