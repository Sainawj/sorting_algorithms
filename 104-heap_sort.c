#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * max_heapify - Ensures that a subtree rooted at given index
 * satisfies the max heap property
 * @array: The array to heapify
 * @size: Size of the array
 */
void max_heapify(int *array, size_t size, int idx)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < (int)size && array[left] > array[largest])
        largest = left;

    if (right < (int)size && array[right] > array[largest])
        largest = right;

    if (largest != idx)
    {
        swap(&array[idx], &array[largest]);
        print_array(array, size);
        max_heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;
   
    if (array == NULL || size < 2)
        return;

       for (i = size / 2 - 1; i >= 0; i--)
        max_heapify(array, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        max_heapify(array, i, 0);
    }
}
