#include <stdio.h>

#include "sort.h"

/**
 * swap - swaps two integers in an array
 *
 * @a: the first integer
 * @b: the second integer
 *
 * Return: return nothing
*/

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *		    Selection sort algorithm
 *
 * @array: the array of integers to sort
 * @size: the size of @array
 *
 * Return: return nothing
*/

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}
		if ((array + i) != min)
		{
			swap(array + i, min);
			print_array(array, size);
		}
	}
}
