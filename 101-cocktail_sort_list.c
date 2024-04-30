#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swaps two nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 * @list: Pointer to the head of the list
 */
void swap_node(listint_t *node1, listint_t *node2, listint_t **list)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
    listint_t *ptr;
    listint_t *left = NULL;
    listint_t *right = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (ptr = *list; ptr->next != right; ptr = ptr->next)
        {
            if (ptr->n > ptr->next->n)
            {
                swap_node(ptr, ptr->next, list);
                print_list(*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        right = ptr;

        swapped = 0;
        for (ptr = ptr->prev; ptr->prev != left; ptr = ptr->prev)
        {
            if (ptr->n < ptr->prev->n)
            {
                swap_node(ptr->prev, ptr, list);
                print_list(*list);
                swapped = 1;
            }
        }
        left = ptr;
    } while (swapped);
}
