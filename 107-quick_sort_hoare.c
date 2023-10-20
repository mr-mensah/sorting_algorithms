#include "sort.h"
/**
 * first_piv - function that finds the piv position
 * @array: array
 * @l: left
 * @r: right
 * @size: size
 * Return: return 0.
 */
int first_piv(int *array, int l, int r, size_t size)
{
	int piv, temp;
	unsigned int a, b;

	piv = array[r];
	a = l - 1;
	b = r + 1;
	while (1)
	{
		do {
			a++;
		} while (array[a] < piv);
		do {
			b--;
		} while (array[b] > piv);
		if (a >= b)
			return (a);
		if (a != b)
		{
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * bring_funct - function that swap array
 * @array: array
 * @l: left
 * @r: right
 * @size: size
 */
void bring_funct(int *array, int l, int r, size_t size)
{
	int piv;

	if (l < r)
	{
		piv = first_piv(array, l, r, size);
		bring_funct(array, l, piv - 1, size);
		bring_funct(array, piv, r, size);
	}
}
/**
 * quick_sort_hoare - function that sorts an array of integers
 * @array: array
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	bring_funct(array, 0, size - 1, size);
}
