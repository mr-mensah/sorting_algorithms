#include "sort.h"
/**
 * swap - function that swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: null
 */
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
/**
 * partition - function that partitions an array
 * @array: array
 * @low: first integer
 * @high: second integer
 * @size: size
 * Return: a
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int a = low - 1, y;
for (y = low; y <= high; y++)
{
if (array[y] <= pivot)
{
a++;
if (a != y)
{
swap(&array[a], &array[y]);
print_array(array, size);
}
}
}
return (a);
}
/**
 * lomuto_qsort - function that sorts an array
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 * Return: null
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
int i;
if (low < high)
{
i = partition(array, low, high, size);
lomuto_qsort(array, low, i - 1, size);
lomuto_qsort(array, i + 1, high, size);
}
}
/**
 * quick_sort - function that use a quick sort algorithm
 * @array: array
 * @size: size
 * Return: null
 */
void quick_sort(int *array, size_t size)
{
lomuto_qsort(array, 0, size - 1, size);
}
