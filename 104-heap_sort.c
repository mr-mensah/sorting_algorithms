#include "sort.h"
/**
* recurssy - function that is recursive
* @array: array
* @head: size
* @a: index
* @size: size
*/

void recurssy(int *array, int head, int a, int size)
{
	int lart = a, left = 2 * a + 1, right = 2 * a + 2, t;

	if (left < head && array[left] > array[lart])
		lart = left;
	if (right < head && array[right] > array[lart])
		lart = right;
	if (lart != a)
	{
		t = array[a], array[a] = array[lart], array[lart] = t;
		print_array(array, size);
		recurssy(array, head, lart, size);
	}
}

/**
* heap_sort - function that sorts array with head sort algo
* @array: array
* @size: size
*/

void heap_sort(int *array, size_t size)
{
	int a = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; a >= 0; a--)
		recurssy(array, size, a, size);
	for (a = size - 1; a >= 0; a--)
	{
		temp = array[0];
		array[0] = array[a];
		array[a] = temp;
		if (a > 0)
			print_array(array, size);
		recurssy(array, a, 0, size);
	}

}
