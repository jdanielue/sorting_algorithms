#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array of imtegers
 * @size: size of the array
 * Return: Notong
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1, outer = 0, inner = 0;
	int v_insert = 0;

	if (array == NULL || size < 2)
		return;

	/* calculate interval*/
	while (interval < (size / 3))
		interval = interval * 3 + 1;

	/* select value to be inserted - seleccionar valor para insertar */
	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			v_insert = array[outer];
			inner = outer;
			/*shift element towards right - desplazar elemento hacia la derecha*/
			while (inner > interval - 1 && array[inner - interval] >= v_insert)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			/* insert the number at hole position */
			array[inner] = v_insert;
		}
		/* calculate interval*/
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
