#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    if (list == NULL)
        return;

    do {
        printf("%d", list->n);
        if (list->next != NULL)
            printf(", ");
        list = list->next;
    } while (list != NULL);
    printf("\n");
}
