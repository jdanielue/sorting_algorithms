#include "sort.h"



void quick_sort(int *array, size_t size)
{
	quick_sort_lomuto(array, 0, size - 1);
	print_array(array, size);
}

void quick_sort_lomuto(int *array, int low, int hi)
{
	int pos;

	if(low < hi)
	{
		pos = parttion(array, low, hi);
		quick_sort_lomuto(array, low, pos - 1);
		quick_sort_lomuto(array, pos + 1, hi);
	}
}

int parttion(int *array, int low, int hi)
{
	int piv = array[hi], i = low, j = 0, tmp = 0;

	for( j = low; j < hi; j++)
	{
		
		if (array[j] < piv)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, 10);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, 10);

	return (i);
}

/*void swap(int *array, int *a, int *b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}*/
