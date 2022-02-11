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
	listint_t *actual = *list, *actprev = (*list)->prev,
		  *sig = (*list)->next, *tmp = *list;

	if (!list || !(*list)->next)
		return;



	while (tmp != NULL)
	{
		tmp = actual->next;
		if (actual->n > sig->n)
		{
			actprev->next = actual->next;
			sig->prev = actual->prev;
			actual->prev = actual->next;
			actual->next = sig->next;
			sig->next = actual;
		}	
		print_list(*list);
	}
}	
