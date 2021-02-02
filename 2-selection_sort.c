#include "sort.h"

/**
 * selection_sort - orts an array of integers in ascending order using the Selection sort
 * @array: array
 * @size: size of array
 * Return: Always 0
 */

void selection_sort(int *array, size_t size)
{
	int temp = 0, indice, menor, cambio = 0;
	size_t i = 0, j = 0;


	for (i = 0; i < size-1; i++)
	{
		menor = array[i];
		j = i;
		while (j < size)
		{
			if (menor > array[j])
			{
				indice = j;
				menor = array[j];
				cambio = 1;
			}
			j++;
		}
		if (cambio == 1)
		{
			temp = array[i];
			array[i] = array[indice];
			array[indice] = temp;
			print_array(array, size);
			cambio = 0;
		}
	}
}