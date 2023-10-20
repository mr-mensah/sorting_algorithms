#include "sort.h"
/**
 * counting_sort - function that sorts an array
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	unsigned int stats, high = 0, j, dump;
	int *temp_array, *count_array;

	if (size < 2)
		return;
	count_array = malloc(size * sizeof(int));
	for (stats = 0; stats < size; stats++)
	{
		if (array[stats] > (int)high)
			high = array[stats];
		count_array[stats] = array[stats];
	}
	high++;
	temp_array = malloc(sizeof(int) * (high));
	if (!temp_array || !count_array)
		return;
	/*fill array with 0s*/
	for (j = 0; j < high; j++)
		temp_array[j] = 0;
	for (stats = 0; stats < size; stats++)
		temp_array[array[stats]]++;
	for (j = 1; j < high; j++)
		temp_array[j] += temp_array[j - 1];
	for (stats = 0; stats < size; stats++)
	{
		dump = temp_array[count_array[stats]] - 1;
		array[dump] = count_array[stats];
	}
	print_array(temp_array, high);
	free(temp_array);
	free(count_array);
}
