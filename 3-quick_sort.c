#include "sort.h"

/**
 *swap - function for change two elements
 *@a: one element
 *@b: one element
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *partition - divide the array in two part
 *@arr: array
 *@low: min position
 *@high: last position
 *@size: size of array
 *Return: return pivot position
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (arr[high] < arr[i + 1])
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 *quick_recursion - Recursion for sort array
 *@array: array
 *@low: min position
 *@high: last position
 *@size: size of array
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_recursion(array, 0, pivot - 1, size);
		quick_recursion(array, pivot + 1, high, size);
	}
}

/**
 *quick_sort - Order an array with lomuto method
 *@array: array to order
 *@size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, 0, size - 1, size);
}
