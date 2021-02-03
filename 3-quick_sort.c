#include "sort.h"



void quick_sort(int *array, size_t size)
{
	quick_sort_lomuto(array, size, 0, size - 1);
}

void quick_sort_lomuto(int *array, size_t size, int low, int hi)
{
	int pos;

	if(low < hi)
	{
		pos = partition(array, size, low, hi);
		quick_sort_lomuto(array, size,  low, pos - 1);
		quick_sort_lomuto(array, size, pos + 1, hi);
	}
}

int partition(int *array, size_t size, int low, int hi)
{
	int piv = array[hi], i = low, j = 0;

	for( j = low; j < hi; j++)
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
