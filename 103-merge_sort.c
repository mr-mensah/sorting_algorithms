#include "sort.h"
#include <stdio.h>
/**
 * merge -  function that sorts array
 * @array: array
 * @size: size
 * @l: pointer
 * @r: pointer
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int a = 0, b = 0, c = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_left);
	printf("[right]: ");
	print_array(r, size_right);

	while (a < size_left && b < size_right)
	{
		if (l[a] < r[b])
			array[c++] = l[a++];
		else
			array[c++] = r[b++];
	}

	while (a < size_left)
		array[c++] = l[a++];

	while (b < size_right)
		array[c++] = r[b++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - function that sorts an array
 * @array: array
 * @size: size
 **/
void merge_sort(int *array, size_t size)
{
	size_t miid = 0, a;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	miid = size / 2;

	for (a = 0; a < miid; a++)
		left[a] = array[a];

	for (a = miid; a < size; a++)
		right[a - miid] = array[a];

	merge_sort(left, miid);
	merge_sort(right, size - miid);
	merge(array, left, right, size);
}
