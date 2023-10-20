#include "sort.h"
/**
 *bubble_sort - function that sort an array of int in ascending order
 *@array: array
 *@size: Size
 */
void bubble_sort(int *array, size_t size)
{
size_t a, b;
int num;
if (array == NULL  || size < 2)
return;
for (b = 0; b < size - 1; b++)
{
for (a = 0; a < size - b - 1; a++)
{
if (array[a] > array[a + 1])
{
num = array[a];
array[a] = array[a + 1];
array[a + 1] = num;
print_array(array, size);
}
}
}
}
