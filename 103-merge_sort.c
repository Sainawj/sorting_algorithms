#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it with zeros
 * @nmemb: Number of elements
 * @size: Size of each element
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i;
    char *p;

    if (nmemb == 0 || size == 0)
        return NULL;

    p = malloc(nmemb * size);
    if (p == NULL)
        return NULL;

    for (i = 0; i < nmemb * size; i++)
        p[i] = 0;

    return p;
}

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @arr: Original array
 * @tmp: Temporary array for merging
 * @start: Starting index of the first subarray
 * @mid: Middle index (end of the first subarray)
 * @end: Ending index of the second subarray
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
    int size_left = mid - start + 1;
    int size_right = end - mid;
    int *array_left = &tmp[0];
    int *array_right = &tmp[size_right];
    int left, right, i = start;

    for (left = 0; left < size_left; left++)
        array_left[left] = arr[start + left];
    for (right = 0; right < size_right; right++)
        array_right[right] = arr[mid + 1 + right];

    left = 0, right = 0;

    while (left < size_left && right < size_right)
    {
        if (array_left[left] <= array_right[right])
            arr[i++] = array_left[left++];
        else
            arr[i++] = array_right[right++];
    }

    while (left < size_left)
        arr[i++] = array_left[left++];
    while (right < size_right)
        arr[i++] = array_right[right++];

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array_left, size_left);
    printf("[right]: ");
    print_array(array_right, size_right);
    printf("[Done]: ");
    print_array(&arr[start], size_left + size_right);
}

/**
 * merge_sort_helper - Helper function for merge sort
 * @array: Array to be sorted
 * @tmp: Temporary array for merging
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 */
void merge_sort_helper(int *array, int *tmp, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort_helper(array, tmp, start, mid);
        merge_sort_helper(array, tmp, mid + 1, end);
        merge(array, tmp, start, mid, end);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp = _calloc(size, sizeof(int));

    if (array == NULL || size < 2)
        return;

    if (tmp == NULL)
        return;

    merge_sort_helper(array, tmp, 0, size - 1);
    free(tmp);
}
