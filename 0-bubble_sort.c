#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, count = 0, j = 0, tmp;

	if (array == NULL || size == 0)
		return;

	count = size - 1;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		count--;
	}
}
