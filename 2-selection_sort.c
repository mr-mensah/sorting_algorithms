#include "sort.h"
/**
 * selection_sort - function that sorts
 *@size:  size
 * @array: array
 */
void selection_sort(int *array, size_t size)
{
size_t j, middle;
int tmp, swap, flag = 0;
if (array == NULL)
return;
for (j = 0; j < size; j++)
{
tmp = j;
flag = 0;
for (middle = j + 1; middle < size; middle++)
{
if (array[tmp] > array[middle])
{
tmp = middle;
flag += 1;
}
}
swap = array[j];
array[j] = array[tmp];
array[tmp] = swap;
if (flag != 0)
print_array(array, size);
}
}
