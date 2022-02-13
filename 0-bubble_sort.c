#include "sort.h"
/**
 *bubble_sort - sort an array of integer in ascending order
 *@array: array for sort
 *@size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int iter;
	int j;
	int aux = 0;
	int ssize = size;

	for (iter = 0; iter < ssize; iter++)
	{
		for (j = 0; j < (ssize - iter - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				print_array(array, size);
			}
		}
	}
}
