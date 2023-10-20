#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers using shell
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	unsigned int spa, a, b, tmp;

	if (size < 2)
		return;
	spa = 1;
	while (spa < size / 3)
		spa = spa * 3 + 1;
	for (; spa > 0; spa = (spa - 1) / 3)
	{
		for (a = spa; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b >= spa && array[b - spa] > (int)tmp; b -= spa)
			{
				array[b] = array[b - spa];
			}
			array[b] = tmp;
		}
		print_array(array, size);

	}
}
