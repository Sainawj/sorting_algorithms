#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array
 * @array: The array
 * @item1: Index of the first element
 * @item2: Index of the second element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
    int tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be partitioned
 * @first: Index of the first element of the partition
 * @last: Index of the last element of the partition
 * @size: Size of the array
 * Return: The position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
    int pivot = array[last];
    ssize_t current = first;
    ssize_t finder;

    for (finder = first; finder < last; finder++)
    {
        if (array[finder] < pivot)
        {
            if (array[current] != array[finder])
            {
                swap(array, current, finder);
                print_array(array, size);
            }
            current++;
        }
    }

    if (array[current] != array[last])
    {
        swap(array, current, last);
        print_array(array, size);
    }

    return (current);
}

/**
 * qs - Implements the quicksort algorithm recursively
 * @array: The array to be sorted
 * @first: Index of the first element
 * @last: Index of the last element
 * @size: Size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
    ssize_t position = 0;

    if (first < last)
    {
        position = lomuto_partition(array, first, last, size);
        qs(array, first, position - 1, size);
        qs(array, position + 1, last, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    qs(array, 0, size - 1, size);
}
