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
	listint_t *actual = NULL, *sig = NULL, *tmp = *list;

	if (!list || !(*list) || !(*list)->next)
		return;

	if (sizeof(list) < 2)
		return;

	for (actual = *list; actual != NULL; actual = actual->next)
	{
		while (actual->next != NULL && actual->n > actual->next->n)
		{
			sig = actual->next;

			while (sig->prev != NULL && sig->n < sig->prev->n)
			{
				tmp = (sig->prev)->prev;

				(sig->prev)->next = sig->next;

				if (sig->next != NULL)
					sig->next->prev = sig->prev;

			(sig->prev)->prev = sig;
			sig->next = sig->prev;
			sig->prev = tmp;

			if (sig->prev != NULL)
				sig->prev->next = sig;
			else
				*list = sig;

			print_list(*list);
			}
		}
	}
}
