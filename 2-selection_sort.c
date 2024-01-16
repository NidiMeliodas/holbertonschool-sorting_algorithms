#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  Selection sort algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	size_t i;
	size_t j;
	size_t min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			/* Swap array[i] and array[min_idx] */
			int temp = array[i];

			array[i] = array[min_idx];
			array[min_idx] = temp;
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
