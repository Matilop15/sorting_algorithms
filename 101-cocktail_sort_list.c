#include "sort.h"

/**
 *swap - function for change elements
 *@actual: actual element
 *@anterior: elemento posicionado anteriormente
 *@list: doubly linked list
 */
void swap(listint_t *actual, listint_t *anterior, listint_t **list)
{
	listint_t *tmp = actual->next;
	listint_t *tmp_2 = anterior->prev;

	if (tmp != NULL)
		tmp->prev = anterior;
	if (tmp_2 != NULL)
		tmp_2->next = actual;

	actual->prev = tmp_2;
	anterior->next = tmp;
	actual->next = anterior;
	anterior->prev = actual;

	if (*list == anterior)
		*list = actual;

	print_list(*list);
}

/**
 *cocktail_sort_list - Order an array with cocktail method
 *@list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *first = NULL, *last = NULL;

	if (list == NULL)
		return;

	do {
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap(tmp->next, tmp, list);
			}
			else
				tmp = tmp->next;
		}
		last = tmp;
		while (tmp->prev != first)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap(tmp, tmp->prev, list);
			}
			else
			{
				tmp = tmp->prev;
			}
		}
		first = tmp;
	} while (first != last);
}

