#include "sort.h"

/**
 * partition - scans a partition of an array of integers for values less than
 * pivot value, swaps first value in partition, swaps pivot
 * value with first value in partition
 * @array: array of integers sort
 * @high: index in array that end partition
 * @size: amount of element in array
 * @low: index in array that ends partition
 * Return: new index to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}
/**
 * quicksort - recursively sorts array of integers by separating into two
 * partition, using lomuto quick sort
 * @high: index in array that ends partiton
 * @array: array of integers sort
 * @low: index in array that begins partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - prepare the terrain for quick sort
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
