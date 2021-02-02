#include "sort.h"

void fuc_quicsort_mia(int *array, int izq, int der)
{

	int i = izq, j = der, tmp;
	int piv = array[(izq + der) / 2];

	printf("entre aca fuc_quicsort_mia\n");
	printf("izq = %d der = %d\n", izq, der);
	printf("i = %d j = %d piv = %d\n", i, j, piv);
	while(i <= j)
	{
		printf("entre aca\n");
		while (array[i] < piv)
			i++;
		while (array[j] > piv)
			j--;
		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}
	if (izq < j)
		fuc_quicsort_mia(array, izq, j);
	if (i < der)
		fuc_quicsort_mia(array, i, der);
}

void quick_sort(int *array, size_t size)
{
	int izq = array[0], der = array[size - 1];
	(void)array;
	(void)size;

	printf("izq = %d der = %d\n", izq, der);
	fuc_quicsort_mia(array, 0, size - 1);
	print_array(array, size);
}
