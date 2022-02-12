#include "sort.h"
/**
 *selection_sort - sorts an array of integers in ascending order
 *@array: array to modify
 *@size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	int aux = 0, i = 0, j = 0, menor = 0, ssize = size;

	if (!array || !size)
		return;

	for (i = 0; i < (ssize - 1); i++)
	{
		menor = i;

		for (j = i + 1; j < ssize; j++)
		{
			if (array[j] < array[menor])
			{
				menor = j;
			}
		}
		if (array[i] > array[menor])
		{
			aux = array[i];
			array[i] = array[menor];
			array[menor] = aux;
			print_array(array, size);
		}
	}
}
