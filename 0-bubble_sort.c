#include <stdio.h>

#include "sort.h"

/**
 * swap - swaps two integers in an       array
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
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: the array of integers
 * @size: the size of @array
 *
 * Description: prints the array after each time there's a swap of two elements
 *
 * Return: return nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swp;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i <= size - 2; i++)
	{
		/* flag to check if end of swap has been reached */
		swp = 0;

		for (j = 0; j <= size - i - 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swp = 1;	/* set swapped flag */
			}
		}
		/* check if swap occurred */
		if (swp == 0)
			break;
	}
}
