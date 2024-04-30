#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int max = array[0];
    int *count;
    size_t i, j = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    count = calloc(max + 1, sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    printf("Counting array:");
    for (i = 0; i <= (size_t)max; i++)
        printf(" %d", count[i]);
    printf("\n");

    for (i = 0; i <= (size_t)max; i++) 
    {
        while (count[i]-- > 0)
            array[j++] = (int)i;
    }

    free(count);
}
