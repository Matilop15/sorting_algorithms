#include "sort.h"
/**
 * shell_sort - sort by shell sorting
 *@array: array for sort
 *@size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t gap = 1, iter, j;


	if (!array || size < 2)
		return;
	/*create a knuth secuence */
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/* start with largest gap */
	while (gap > 0)
	{
		for (iter = gap; iter < size; iter++)
		{	/*save the element have be sorted*/
			tmp = array[iter];
			/*change the element in correct location*/
			for (j = iter; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			/*paste tmp in correct location*/
			array[j] = tmp;
		}
	/* decreasing the interval */
	gap = gap / 3;
	print_array(array, size);
	}
}
