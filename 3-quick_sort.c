#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of imtegers
 * @size: size of the array
 * Return: Notong
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, size, 0, size - 1);
}

/**
 * quick_sort_lomuto - function that sort array with implement Lomuto
 * @array: array of imtegers
 * @size: size of the array
 * @low: less elemet of the array
 * @hi: high elemt of the array
 * Return: Noting
 */


void quick_sort_lomuto(int *array, size_t size, int low, int hi)
{
	int pos;

	if (low < hi)
	{
		pos = partition(array, size, low, hi);
		quick_sort_lomuto(array, size,  low, pos - 1);
		quick_sort_lomuto(array, size, pos + 1, hi);
	}
}

/**
 * partition - function that separate of the elemnts of the array
 * @array: array of imtegers
 * @size: size of the array
 * @low: less elemet of array
 * @hi: high elemt of array
 * Return: position current of array
 */

int partition(int *array, size_t size, int low, int hi)
{
	int piv = array[hi], i = low, j = 0;

	for (j = low; j < hi; j++)
	{
		if (array[j] < piv)
		{
			swap(array, size, i, j);
			i++;
		}
	}
	swap(array, size, i, j);

	return (i);
}

/**
 * swap - function that change elemnts
 * @array: array of imtegers
 * @size: size of the array
 * @a: element to change
 * @b: element to change
 * Return: Noting
 */

void swap(int *array, size_t size, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
		print_array(array, size);
	}
}
